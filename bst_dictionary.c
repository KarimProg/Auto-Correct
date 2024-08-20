#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node node;

struct node
{
  char word[50];
  node *left;
  node *right;
};

node *initNode(char *word)
{
  node *bst = malloc(sizeof(node));
  strcpy(bst->word, word);
  bst->left = NULL;
  bst->right = NULL;

  return bst;
}

node *insertWord(node *head, char *word)
{

  if (head == NULL)
  {
    return initNode(word);
  }
  if (strcasecmp(head->word, word) > 0)
  {
    head->left = insertWord(head->left, word);
  }
  else
  {
    head->right = insertWord(head->right, word);
  }
  return head;
}

void displayBST(node *head)
{
  if (head == NULL)
    return;

  displayBST(head->left);
  printf("%s, ", head->word);
  displayBST(head->right);
}

int getHeight(node *head, int max, int progress)
{
  if (head == NULL)
  {
    return progress;
  }

  int num = getHeight(head->left, max, progress + 1);
  max = num > max ? num : max;
  num = getHeight(head->right, max, progress + 1);
  max = num > max ? num : max;

  return max;
}

char *findSuccessor(node *head, char *word)
{
  node *successor = NULL;

  while (head != NULL)
  {
    if (strcasecmp(head->word, word) <= 0)
    {
      head = head->right;
    }
    else
    {
      successor = head;
      head = head->left;
    }
  }

  return successor ? successor->word : NULL;
}

char *findPredecessor(node *head, char *word)
{
  node *predecessor = NULL;

  while (head != NULL)
  {
    if (strcasecmp(head->word, word) >= 0)
    {
      head = head->left;
    }
    else
    {
      predecessor = head;
      head = head->right;
    }
  }

  return predecessor ? predecessor->word : NULL;
}

void spellCheck(node *head, char *word)
{
  node *current = head;
  node *lastNodeReached = NULL;

  while (current != NULL)
  {
    lastNodeReached = current;

    if (strcasecmp(current->word, word) == 0)
    {
      printf("%s - CORRECT\n", current->word);
      return;
    }

    if (strcasecmp(current->word, word) > 0)
    {
      current = current->left;
    }
    else
    {
      current = current->right;
    }
  }

  char *successor = findSuccessor(head, lastNodeReached->word);
  char *predecessor = findPredecessor(head, lastNodeReached->word);

  printf("%s - Incorrect, Suggestions: %s %s %s\n", word,
         lastNodeReached->word,
         successor ? successor : "No successor",
         predecessor ? predecessor : "No predecessor");
}

int main()
{
  node *head = NULL;
  FILE *f = fopen("Dictionary.txt", "r");
  char buffer[50];
  int size = 0;
  while (!feof(f))
  {
    fscanf(f, "%s", &buffer);
    head = insertWord(head, buffer);
    size++;
  }

  printf("Size: %d\n", size);
  printf("Height: %d\n", getHeight(head, -1, -1));

  char sentence[200];
  printf("Enter a sentence :\n");
  fgets(sentence, 200, stdin);
  char *w = strtok(sentence, " ");
  while (w != NULL)
  {
    if (w[strlen(w) - 1] == '\n')
      w[strlen(w) - 1] = '\0';
    spellCheck(head, w);
    printf("\n");

    w = strtok(NULL, " ");
  }

  return 0;
}