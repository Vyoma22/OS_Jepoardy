/*
 
Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
CRN 74027 / Group 13 / Project: Jeopardy Game

 
Copyright (C) 2015,
Vyoma Shah
Maisha Zarrin Subha
Wang Ying Su
Marwan Allam
All rights reserved.**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "questions.h"
#include "players.h"
#include "jeopardy.h"

#define BUFFER_LEN 256
#define NUM_PLAYERS 4

void tokenize(char *input, char **tokens);
void show_results(player *players, int num_players);

int main(int argc, char *argv[])
{
    player players[NUM_PLAYERS];
    char buffer[BUFFER_LEN] = { 0 };

    // Initialize the game
    initialize_game();

    // Prompt for players names
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("Enter name for player %d: ", i + 1);
        fgets(players[i].name, MAX_LEN, stdin);
        players[i].name[strcspn(players[i].name, "\n")] = 0; // Remove newline
        players[i].score = 0; // Initialize score
    }

    // Game loop
    while (1) {
        display_categories();
        char player_name[MAX_LEN];
        printf("Enter the name of the player selecting a question: ");
        fgets(player_name, MAX_LEN, stdin);
        player_name[strcspn(player_name, "\n")] = 0; // Remove newline

        if (!player_exists(players, NUM_PLAYERS, player_name)) {
            printf("Player not found. Please try again.\n");
            continue;
        }

        char category[MAX_LEN];
        int value;
        printf("Enter category and dollar amount (e.g., programming 200): ");
        fgets(buffer, BUFFER_LEN, stdin);
        sscanf(buffer, "%s %d", category, &value);

        if (already_answered(category, value)) {
            printf("This question has already been answered. Please select another.\n");
            continue;
        }

        display_question(category, value);
        printf("Your answer: ");
        fgets(buffer, BUFFER_LEN, stdin);

        // Tokenize the answer
        char *tokens[3]; // We expect at most 3 tokens: "what", "is", "answer"
        tokenize(buffer, tokens);

        // Check if the answer starts with "what is" or "who is"
        if (tokens[0] != NULL && tokens[1] != NULL) {
            // Combine the rest of the tokens to form the answer
            char answer[MAX_LEN] = "";
            for (int j = 2; tokens[j] != NULL; j++) {
                strcat(answer, tokens[j]);
                strcat(answer, " "); // Add space between words
            }
            answer[strcspn(answer, "\n")] = 0; // Remove newline

            // Validate the answer
            if (valid_answer(category, value, answer)) {
                printf("Correct!\n");
                update_score(players, NUM_PLAYERS, player_name, value);
            } else {
                // Find the correct answer to display
                for (int i = 0; i < NUM_QUESTIONS; i++) {
                    if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
                        printf("Incorrect! The correct answer was: %s\n", questions[i].answer);
                        break;
                    }
                }
            }
        } else {
            printf("Please start your answer with 'what is' or 'who is'.\n");
        }

        // Mark question as answered
        for (int i = 0; i < NUM_QUESTIONS; i++) {
            if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
                questions[i].answered = true;
                break;
            }
        }

        // Check if all questions are answered
        bool all_answered = true;
        for (int i = 0; i < NUM_QUESTIONS; i++) {
            if (!questions[i].answered) {
                all_answered = false;
                break;
            }
        }
        if (all_answered) {
            break; // Exit the game loop
        }
    }

    // Show results
    show_results(players, NUM_PLAYERS);
    return EXIT_SUCCESS;
}

void tokenize(char *input, char **tokens)
{
    // Tokenize the input based on spaces
    char *token = strtok(input, " ");
    int i = 0;
    while (token != NULL && i < 3) { // Expecting at most 3 tokens
        tokens[i++] = token;
        token = strtok(NULL, " ");
    }
    tokens[i] = NULL; // Null-terminate the tokens array
}

void show_results(player *players, int num_players)
{
    printf("Final Results:\n");
    for (int i = 0; i < num_players; i++) {
        printf("%s: $%d\n", players[i].name, players[i].score);
    }
}