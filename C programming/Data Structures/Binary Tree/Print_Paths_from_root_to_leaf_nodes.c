#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree_integer {
    int value;
    struct tree_integer *left;
    struct tree_integer *right;
} tree_integer;

typedef struct {
    char **arr;
    int size;
} arr_string;

// Function to convert an integer to a string
char *intToString(int num) {
    char *str = (char *)malloc(20 * sizeof(char));
    sprintf(str, "%d", num);
    return str;
}

// Helper function to create the path from root to leaf
void getPath(tree_integer *node, char *currentPath, char ***paths, int *count) {
    if (node == NULL) {
        return;
    }

    char *nodeStr = intToString(node->value);
    char *newPath = (char *)malloc((strlen(currentPath) + strlen(nodeStr) + 3) * sizeof(char));
    strcpy(newPath, currentPath);
    if (strlen(currentPath) > 0) {
        strcat(newPath, "->");
    }
    strcat(newPath, nodeStr);

    if (node->left == NULL && node->right == NULL) {
        // Leaf node, add the path to the array
        (*paths)[(*count)] = newPath;
        (*count)++;
    } else {
        // Continue the path
        getPath(node->left, newPath, paths, count);
        getPath(node->right, newPath, paths, count);
    }

    free(nodeStr);
}

arr_string solution(tree_integer *t) {
    arr_string result;
    result.size = 0;
    result.arr = NULL;

    if (t == NULL) {
        return result;
    }

    char **paths = (char **)malloc(1000 * sizeof(char *));
    int count = 0;

    getPath(t, "", &paths, &count);

    result.size = count;
    result.arr = paths;
    
    return result;
}

int main() {
    // Example usage
    tree_integer node1 = {1, NULL, NULL};
    tree_integer node2 = {2, NULL, NULL};
    tree_integer node3 = {3, NULL, NULL};
    tree_integer node4 = {4, &node1, &node2};
    tree_integer node5 = {5, NULL, &node3};
    tree_integer root = {0, &node4, &node5};

    arr_string result = solution(&root);

    for (int i = 0; i < result.size; i++) {
        printf("%s\n", result.arr[i]);
        free(result.arr[i]);
    }

    free(result.arr);

    return 0;
}


/*
0->4->1
0->4->2
0->5->3
*/
