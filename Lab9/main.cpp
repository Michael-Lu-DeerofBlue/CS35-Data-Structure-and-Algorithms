/*
  Copyright (c) 2023
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2023
  CPSC 035: Data Structures and Algorithms
*/

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

#include "ioUtils.h"
#include "railwayGUI.h"
#include "player.h"
#include "railwayGame.h"
using namespace std;

int main(int argc, char** argv) {
    // Check command line arguments and give up if necessary.
    if (argc != 2) {
        cerr << "Expected one argument:" << endl;
        cerr << "  Base filename of map data" << endl;
        cerr << "  e.g., test_data/Europe " << endl;
        return 1;
    }

    // Initialize randomizer.  This should happen before any random numbers are
    // selected.
    srand(time(nullptr));

    // Get command-line arguments.
    string baseName(argv[1]);
    string graphDataFilename = baseName + "_graphData.txt";
    string vertexPositionFilename = baseName + "_vertexPositions.txt";
    string backgroundImageFilename = baseName + "_background.png";

    // Retrieve vertex positions (so we know where each vertex goes on the map).
    Dictionary<string, pair<int, int>>* vertexPositions;
    try {
        vertexPositions = readVertexPositions(vertexPositionFilename);
    } catch (exception e) {
        cout << "Could not read vertex positions file "
             << vertexPositionFilename << ": " << e.what() << endl;
        return 1;
    }

    // Load the initial graph.
    Graph<string, int, int>* graph;
    try {
        graph = readRailwayGraph(graphDataFilename);
    } catch (exception e) {
        cout << "Could not read graph data file " << graphDataFilename << ": "
             << e.what() << endl;
        delete vertexPositions;
        return 1;
    }

    // Create the GUI object here.  This is statically allocated, so the GUI
    // will disappear the moment your program leaves the main function.
    // The GUI object should only be used by main, and not by any other function
    // or object.
    RailwayGUI gui(backgroundImageFilename, vertexPositions);

    // Tell the GUI about the graph we have.
    gui.updateRailwayMap(graph);
    //set up game
    vector<string> message;
    bool playerSwitch=false;
    int currentPlayer =1;
    RailwayGame* game = new RailwayGame(graph);
    Player* P1 = game->getPlayer1();
    Player* P2 = game->getPlayer2();
    //update player status
    gui.updatePlayerStatus(1,P1->getScore(),P1->getTracks(),P1->getGoals());
    gui.updatePlayerStatus(2,P2->getScore(),P2->getTracks(),P2->getGoals());
    gui.updateMessage("It is Player 1's turn" );
    //while loop that runs game
    while(true){
        //if statements handle tracking whos turn it is
        message = gui.getNextMove();
        if (message[0] == "pass"){
            game->passUpdate(currentPlayer);
            currentPlayer = game->turn();
            gui.updateMessage("It is Player " + to_string(currentPlayer) + "'s turn" );
        }
        else if (message[0] == "close"){
            break;
        }
        else{
            //setEdge checks if a player can choose the edge, then returns if it was successful. Score calculations only happen if successful
            int result = game->setEdge(message[1], message[2], currentPlayer);
            if (result == 0){   //success
                gui.updateRailwayMap(graph);
                game->calculateScore();
                currentPlayer = game->turn();
                gui.updateMessage("It is Player " + to_string(currentPlayer) + "'s turn" );
            }
            else if (result == 1){      //failure
                gui.updateMessage("Invalid path chosen: Try again Player " + to_string(game->getCurrentPlayer()));
                continue;
            }
        }
        gui.updatePlayerStatus(1,P1->getScore(),P1->getTracks(),P1->getGoals());
        gui.updatePlayerStatus(2,P2->getScore(),P2->getTracks(),P2->getGoals());
    }
    // Finally, clean up and exit successfully.
    delete game;
    delete graph;
    delete vertexPositions;
    return 0;
}