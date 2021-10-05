#define MAXELEMENTS 100 // Size of rows & colums.


struct Stack{
	int xtop;
    int xback;
	int xfront;

    int ytop;
    int yback;
	int yfront;

	int entry[MAXELEMENTS][MAXELEMENTS];
};

// Create Truck.
void creattruck(Stack *ps){
	ps->xtop=0;
    ps->xback=0;
    ps->xfront=0;

    ps->ytop=MAXELEMENTS/2;
    ps->yback=(MAXELEMENTS/2)+1;
    ps->yfront=(MAXELEMENTS/2)-1;
}

// Check if Truck is full from top.
int TruckFulltop(Stack *ps){
	return MAXELEMENTS == ps->xtop;
	
}

// Check if Truck is full from back.
int TruckFullback(Stack *ps){
	return (MAXELEMENTS == ps->xback);
	
}

// Check if Truck is full from front.
int TruckFullfront(Stack *ps){
	return MAXELEMENTS == ps->xfront;
	
}

/*
    Push elemnt to top
    pre condition Truck is not full from top.
*/
void pushtop(int e, Stack *ps){
	ps->entry[ps->xtop++][ps->ytop]=e;
}

/*
    Push elemnt to back
    pre condition Truck is not full from back.
*/
void pushback(int e, Stack *ps){
    
	ps->entry[ps->xback][ps->yback++]=e;

    if(ps->yback==MAXELEMENTS){
        ps->xback++;
        ps->yback=(MAXELEMENTS/2)+1;
    }
}

/*
    Push elemnt to front
    pre condition Truck is not full from front.
*/
void pushfront(int e, Stack *ps){
    
	ps->entry[ps->xfront][ps->yfront--]=e;
    if(ps->yfront < 0){
         ps->xfront++;
         ps->yfront = (MAXELEMENTS/2)-1;
     }
}

/*
    pop elemnt from front
    pre condition Truck is not empty from front.
*/
void popfront(int *pe, Stack *ps){
    

     if(ps->yfront == (MAXELEMENTS/2)-1){
         ps->xfront--;
         ps->yfront = -1;
        
     }
        *pe=ps->entry[ps->xfront][++ps->yfront];

}

/*
    pop elemnt from top
    pre condition Truck is not empty from top.
*/
void poptop(int *pe, Stack *ps){
	 *pe=ps->entry[--ps->xtop][ps->ytop];
}

/*
    pop elemnt from back
    pre condition Truck is not empty from back.
*/
void popback(int *pe, Stack *ps){
    if(ps->yback == (MAXELEMENTS/2)+1){
        ps->xback--;
        ps->yback = MAXELEMENTS;
    }
	 *pe=ps->entry[ps->xback][--ps->yback];
}


// Check Truck is empty from top.
int StackEmptytop(Stack *ps){
	return !ps->xtop;
}

// Check Truck is empty from back.
int StackEmptyback(Stack *ps){
	return (!ps->xback) && (ps->yback = MAXELEMENTS/2);
}

// Check Truck is not empty from front.
int StackEmptyfront(Stack *ps){
	return (!ps->xfront) && (ps->yfront = MAXELEMENTS/2);
}

