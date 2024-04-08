#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "stack_char.h"

void displayStack(stack_t s) {
	printf("\nThe Content of the Stack\n");
	while (!isEmptyS(&s))
		printf("%c ", pop(&s));
	printf("\n");
}

int isLower(SType ch) {
	if (ch >= 'a' && ch <= 'z')
		return 1;
	return 0;
}

int remAllLower(stack_t* s) {
	stack_t temp;
	initializeS(&temp);

	int count = 0;
	char ch;

	while (!isEmptyS(s)) {
		ch = pop(s);
		if (!isLower(ch))
			push(&temp, ch);
		else
			count++;
	}

	while (!isEmptyS(&temp)) 
		push(s, pop(&temp));
	
	return (count);
}

int main(void)
{
	SType ch;
	stack_t s;
	initializeS(&s);
	do {
		printf("Enter a charracter (or ! to stop): ");
		scanf(" %c", &ch);
		if (ch != '!')
			push(&s, ch);
	} while (ch != '!');

	displayStack(s);

	int lowerNum = remAllLower(&s);
	if (lowerNum != 0) {
		printf("\nThe #of lowercase letters in the stack is: %d\n", lowerNum);
		printf("All lowercase letters were delted\n");
		displayStack(s);
	}
	else
		printf("\nThe stack does not conation any lowercase letters\n");

	return 0;
}