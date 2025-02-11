/*
 
Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
CRN 74027 / Group 13 / Project: Jeopardy Game

 
Copyright (C) 2015,
Vyoma Shah
Maisha Zarrin Subha
Wang Ying Su
Marwan Allam
All rights reserved.**/

#ifndef JEOPARDYH
#define JEOPARDYH

#define MAX_LEN 256

// Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
extern void tokenize(char input, char **tokens);

// Displays the game results for each player, their name and final score, ranked from first to last place
extern void show_results(playerplayers, int num_players);

#endif /* JEOPARDYH */