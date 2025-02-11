/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 * CRN 74027 / Group 13 / Project: Jeopardy Game
 *
 * Copyright (C) 2015, 
 * Vyoma Shah
 * Maisha Zarrin Subha
 * Wang Ying Su
 * Marwan Allam
 * All rights reserved.
 *
 */
#ifndef QUESTIONS_H_
#define QUESTIONS_H_

#include <stdbool.h>

#define MAX_LEN 256
#define NUM_CATEGORIES 3
#define NUM_QUESTIONS 12

// Questions struct for each question
typedef struct {
    char category[MAX_LEN];
    char question[MAX_LEN];
    char answer[MAX_LEN];
    int value;
    bool answered;
} question;

// Declare the questions array as extern
extern question questions[NUM_QUESTIONS];

// List of 3 categories as array of strings
static char categories[NUM_CATEGORIES][MAX_LEN] = {
    "programming",
    "algorithms",
    "databases"
};

// Function declarations
extern void initialize_game(void);
extern void display_categories(void);
extern void display_question(char *category, int value);
extern bool valid_answer(char *category, int value, char *answer);
extern bool already_answered(char *category, int value);

#endif /* QUESTIONS_H_ */