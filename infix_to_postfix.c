
#include <stdio.h>
#include <ctype.h>
#define SIZE 50
struct stack {
	char st[SIZE];
	int top;
} s;
void push(char elem)
{
	s.st[++s.top]=elem;
}

char pop()
{
	return(s.st[s.top--]);
}
int p(char elem)
{
	switch(elem)
	{
	case '#':
	{
		return 0;
	}
	case '(':
	{
		return 1;
	}
	case '+':
	{
	    return 2;
	}
	case '-':
		return 2;
	case '*':
	{
	    return 3;
	}
	case '/':
		return 3;
	}
}

void main()
{
	char in[50], po[50], ch, elem;
	s.top=-1;
	int i=0, k=0;
	{
		printf("\nRead the Infix Expression: ");
		scanf("%s",in);
		push('#');
		while( (ch=in[i++]) != '\0')
		{
			if( ch == '(' ) {
			    push(ch);
			}
			else if(isalnum(ch)){
			    po[k++]=ch;
			} 
			else if( ch == ')' )
			{
				while( s.st[s.top] != '(' )
				{
					po[k++]=pop();
				}
				elem=pop();
			}
			else
			{
				while( p(s.st[s.top]) >= p(ch) )
					po[k++]=pop();
				push(ch);
			}
		}
		while( s.st[s.top] != '#' )
			po[k++]=pop();
		po[k]='\0';
		printf("\nPostfix exp is: %s\n",po);

	}
}

