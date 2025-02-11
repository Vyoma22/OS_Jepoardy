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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "questions.h"

// Define the questions array
question questions[NUM_QUESTIONS];

// Initializes the array of questions for the game
void initialize_game(void)
{
    // Sample questions for each category
    // Programming Questions
    strcpy(questions[0].category, "programming");
    strcpy(questions[0].question, "What is the main function in C?");
    strcpy(questions[0].answer, "main");
    questions[0].value = 200;
    questions[0].answered = false;

    strcpy(questions[1].category, "programming");
    strcpy(questions[1].question, "What is the keyword to define a constant?");
    strcpy(questions[1].answer, "const");
    questions[1].value = 400;
    questions[1].answered = false;

    strcpy(questions[2].category, "programming");
    strcpy(questions[2].question, "What is the data type for true/false values?");
    strcpy(questions[2].answer, "bool");
    questions[2].value = 600;
    questions[2].answered = false;

    strcpy(questions[3].category, "programming");
    strcpy(questions[3].question, "What is the symbol for the logical AND operator?");
    strcpy(questions[3].answer, "&&");
    questions[3].value = 800;
    questions[3].answered = false;

    // Algorithm Questions
    strcpy(questions[4].category, "algorithms");
    strcpy(questions[4].question, "What is the time complexity of linear search?");
    strcpy(questions[4].answer, "linear");
    questions[4].value = 200;
    questions[4].answered = false;

    strcpy(questions[5].category, "algorithms");
    strcpy(questions[5].question, "What is the algorithm used for sorting in place?");
    strcpy(questions[5].answer, "quicksort");
    questions[5].value = 400;
    questions[5].answered = false;

    strcpy(questions[6].category, "algorithms");
    strcpy(questions[6].question, "What is the data structure used for LIFO?");
    strcpy(questions[6].answer, "stack");
    questions[6].value = 600;
    questions[6].answered = false;

    strcpy(questions[7].category, "algorithms");
    strcpy(questions[7].question, "What is the algorithm used for finding the shortest path?");
    strcpy(questions[7].answer, "dijkstra");
    questions[7].value = 800;
    questions[7].answered = false;

    // Database Questions
    strcpy(questions[8].category, "databases");
    strcpy(questions[8].question, "What does SQL stand for?");
    strcpy(questions[8].answer, "structured");
    questions[8].value = 200;
    questions[8].answered = false;

    strcpy(questions[9].category, "databases");
    strcpy(questions[9].question, "What is the unique identifier in a database table?");
    strcpy(questions[9].answer, "primary");
    questions[9].value = 400;
    questions[9].answered = false;

    strcpy(questions[10].category, "databases");
    strcpy(questions[10].question, "What is the language used to query databases?");
    strcpy(questions[10].answer, "sql");
    questions[10].value = 600;
    questions[10].answered = false;

    strcpy(questions[11].category, "databases");
    strcpy(questions[11].question, "What is the term for a collection of related data?");
    strcpy(questions[11].answer, "table");
    questions[11].value = 800;
    questions[11].answered = false;
}

// Displays each of the remaining categories and question dollar values that have not been answered
void display_categories(void)
{
    printf("Remaining Categories and Values:\n");
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (!questions[i].answered) {
            printf("%s - $%d\n", questions[i].category, questions[i].value);
        }
    }
}

// Displays the question for the category and dollar value
void display_question(char *category, int value)
{
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
            printf("Question: %s\n", questions[i].question);
            return;
        }
    }
    printf("Question not found.\n");
}

// Returns true if the answer is correct for the question for that category and dollar value
bool valid_answer(char *category, int value, char *answer)
{
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
            return strcmp(questions[i].answer, answer) == 0; // Compare the answers
        }
    }
    return false;
}

// Returns true if the question has already been answered
bool already_answered(char *category, int value)
{
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
            return questions[i].answered;
        }
    }
    return false;
}