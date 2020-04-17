#include "BeelzebubLang.h"


//ÈôÕ»SÎª¿ÕÕ»,·µ»Øtrue,·ñÔò·µ»Øfalse
int StackEmpty(SqStack *S)
{
    if(S->top==S->base)
	return true;
	else 
	return 0;	
}
