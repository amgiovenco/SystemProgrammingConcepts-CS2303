#include <stdio.h>
#include <stdlib.h>
#include "binaryTree.h" 


/*****************************************************
 * int main();
 *    determines the number of input files, opens 
 *    each, and scans each word. Will add scanned words
 *    to binary tree. Opens all_counts.txt file for output.
 *    Prints to all_counts.txt
 * intput-
 *   ./countWords input_data1.txt input_data2.txt
 * returns-
 *    List printed in all_counts.txt
 ******************************************************/
int main(int argc, char *argv[]) {
    
    FILE *f1;
    int branch = 100;
    BinaryTree ptree; // Declare a binary tree named ptree.
    InitializeTree(&ptree); // Calls function InitalizeTree

    for (int i = 1; i < argc; i++) {
        f1 = fopen(argv[i], "r"); //Open to current input file
        for(int j = 1; j < branch; j++) {
           char word[100];
           while (fscanf(f1, "%s", word) == 1) { //Reads from current input file and adds to binary tree
            AddItem(word, &ptree);
           } 
        }
        
        fclose(f1); //Close current input file
    }

    f1 = fopen("all_counts.txt", "w"); // Open all_counts.txt for writing words and counts.

    fprintf(f1, "Counts Word\n"); //Prints Header
    printToFile(&ptree, f1); //Print words and their counts to the output file.
    

    WordNode* mostCommon = find_max(ptree.root);  //Find the node with the highest count in the tree.
    WordNode* leastCommon = find_min(ptree.root);  //Find the node with the smallest count in the tree.

    printf("The most common word is \"%s\".\n", mostCommon->word); //Print the most common word.
    printf("The least common word is \"%s\".\n", leastCommon->word);  //Print the least common word.

    fclose(f1); //Close file
}


/*****************************************************
 * WordNode* find_max(WordNode* start);
 *    finds max count in tree
 * intput-
 *    start: A pointer to a node in the Binary Tree
 * returns-
 *    A pointer to the node on the tree with the highest count
 ******************************************************/
WordNode* find_max(WordNode* start) {
    if (start == NULL) { //To avoid a segmentation fault
        return NULL;
    }

    WordNode *maxNode = start;
    WordNode *leftMax = find_max(start->left);
    WordNode *rightMax = find_max(start->right);
    
    if (leftMax != NULL && leftMax->count > maxNode->count) {
        maxNode = leftMax;
    }
    if (rightMax != NULL && rightMax->count > maxNode->count) {
        maxNode = rightMax;
    }

    return maxNode;
}


/*****************************************************
 * WordNode* find_min(WordNode* start);
 *    finds min count in tree
 * input-
 *    start: A pointer to a node in the Binary Tree
 * returns-
 *    A pointer to the node on the tree with the lowest count
 ******************************************************/
WordNode* find_min(WordNode* start) {
    if (start == NULL) {
        return NULL;
    }

    WordNode *minNode = start;
    WordNode *leftMin = find_min(start->left);
    WordNode *rightMin = find_min(start->right);

    if (leftMin != NULL && leftMin->count < minNode->count) {
        minNode = leftMin;
    }
    if (rightMin != NULL && rightMin->count < minNode->count) {
        minNode = rightMin;
    }

    return minNode;
}

