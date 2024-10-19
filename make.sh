#!/bin/bash

g++ -c sfml.cpp -lm &&
g++ sfml.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system &&
./sfml-app
