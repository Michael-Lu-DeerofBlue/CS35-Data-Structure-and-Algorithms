/*
  Copyright (c) 2023
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2023
  CPSC 035: Data Structures and Algorithms
*/
#include "goal.h"
#include "player.h"
#include "adts/graph.h"

#pragma once
using namespace std;
/**
 * An instance of this class represents a single game of Railway.  An object of
 * type RailwayGame does not represent the user interface, but does represent
 * the idea of a game of Railway, including the state of the board and all of
 * the information pertaining to both players.  It also includes the logic for
 * making moves in the game and enforces the game's rules.
 */
class RailwayGame {
  public:
    /*
    constructs a railway game object
    graph: the game graph containing the cities and the tracks
    */
    RailwayGame(Graph<string, int, int>* graph);
    /*
    destructs a railway game object
    */
    ~RailwayGame();
    /*
    switch the players after a successful move or a pass
    return an int representing player 1 or 2
    */
    int turn();
    /*
    claim an edge in the graph for a player
    V1: the first vertex
    V2: the second vertex
    currentPlayer: an int representing player 1 or 2
    return 0 when it's a success move, 1 when it's not
    */
    int setEdge(string V1, string V2, int currentPlayer);
    /*
    calculate the score of the current player
    */
    void calculateScore();
    /*
    get a pointer to Player 1
    return a pointer to Player 1
    */
    Player* getPlayer1();
    /*
    get a pointer to Player 2
    return a pointer to Player 2
    */
    Player* getPlayer2();
    /*
    get an int representing the current Player
    return an int representing the current Player
    */
    int getCurrentPlayer();
    /*
    update the number of tracks when the player hits pass
    currentPlayer: an int representing player 1 or 2
    */
    void passUpdate(int currentPlayer);


  private:
    Player* P1; //a pointer to Player 1
    Player* P2; //a pointer to Player 2
    Player* curr; //a pointer to current Player
    Graph<string, int, int>* graph; //a pointer to the game graph
    int currentPlayer; //a int representing the current Player
    /*
    set the goals for the railway game
    cityNames: the vector of the city names in the graph
    return a vector of goal pointers
    */
    vector<Goal*> setGoals(vector<string> cityNames);
    // You can safely ignore the following code.  This eliminates some default
    // class routines, preventing you from using them accidentally.
    // Specifically, we are disabling the use of the copy constructor and the
    // copy assignment operator.  You can read more here:
    //   http://www.cplusplus.com/articles/y8hv0pDG/
    RailwayGame(const RailwayGame& game) = delete;
    RailwayGame& operator=(const RailwayGame& game) = delete;
    int turn1;
};
