#!/bin/bash

# Infers whether each of the Shape classes has been defined.  Writes to the
# file testConstants.h.

(
  for n in horizontalLine point rectangle verticalLine; do
    classname="$(echo -n ${n:0:1} | tr '[:lower:]' '[:upper:]')${n:1}"
    cat "$n.h" | egrep -v '^\s*//' | egrep "class +$classname" >&/dev/null && \
        echo "#define DECLARED_$(echo -n "$n" | tr '[:lower:]' '[:upper:]')" \
        || :
  done
) > .shapeConstants.h
if [ -f shapeConstants.h ]; then
  diff .shapeConstants.h shapeConstants.h >&/dev/null || mv {.,}shapeConstants.h
else
  mv {.,}shapeConstants.h
fi
rm -f .shapeConstants.h
