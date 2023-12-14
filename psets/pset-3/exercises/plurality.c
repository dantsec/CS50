#include <stdio.h>
#include <cs50.h>
#include <string.h>

// MAX SIZE CANDIDATES ARRAY
#define MAX 9

typedef struct {
    string name;
    int votes;
} candidate;

// CANDIDATES ARRAY
candidate candidates[MAX];

// 'ALIAS' TO ARGC
int candidate_count = 0;

// PROTOTYPES
int vote(char*);
void print_winner(void);

int main(int argc, char *argv[]) {
    // VARS
    int voter_count = 0;
    candidate_count = argc - 1;

    // INPUT
    if(argc < 2) {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // VERIFY NUMBER OF CANDIDATES
    if(argc - 1 > MAX) {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }

    // FILLING IN ARRAY
    for(int i = 0; i < argc - 1; i++) {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    voter_count = get_int("Number of voters: ");

    // VERFIFY VOTES
    for(int i = 0; i < voter_count; i++) {
        string name = get_string("Vote: ");

        if(!vote(name))
            printf("Invalid vote.\n");
    }

    print_winner();

    return 0;
}

// SEARCH CANDIDATE NAME AND INCREMENT YOUR VOTE
int vote(char *name) {
    for(int i = 0; i < candidate_count; i++) {
        if(strcmp(candidates[i].name, name) == 0) {
            candidates[i].votes += 1;
            return 1;
        }
    }

    return 0;
}

void print_winner(void) {
    // FOUND 'EST CANDIDATE VOTES
    int max_value = 0;

    for(int i = 0; i < candidate_count; i++)
        if(candidates[i].votes > max_value)
            max_value = candidates[i].votes;

    // PRINT CANDIDATES WITH VOTES == MAX_VALUE
    for(int i = 0; i < candidate_count; i++)
        if(candidates[i].votes == max_value)
            printf("%s\n", candidates[i].name);
}
