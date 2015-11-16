#define MAX_X 48
#define MAX_Y 24
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

enum Openlist{close=-1, none=0, open=1};
struct Node{
	Openlist openlist = none;
	char num;
	int x;
	int y;
	int s=0;
	int h=0;
	int g=0;
	Node *link = NULL;
	Node *pre = NULL;
};

struct SpecialNode{
	int x;
	int y;
};


struct NodeList{
	Node node[MAX_X][MAX_Y];
};
void cal(Node *node,const Node *now,SpecialNode g, int i ,int j);
void SetValue(NodeList *list, SpecialNode *g, SpecialNode *s);
void SetStarValue(NodeList *list, SpecialNode *s);
void SetOverValue(NodeList *list, SpecialNode *g);
int InputFile(NodeList *list, SpecialNode *g, SpecialNode *s);
void OutputFile(NodeList *list , Node *now);
void Add_to_list(Node *listnode, Node node);
int choose_next_now_node(NodeList *list, Node **now);
void Display(const NodeList *list);
void delay(int);


void cal(Node *node,const Node *now,SpecialNode g, int i ,int j){
	if(now->x == j || now->y == i)
		node->g = now->g + 10;
	else
		node->g = now->g + 14;
	
	node->h = (abs(g.x-j) + abs(g.y-i)) * 10;
	
	node->s = node->g + node->h;
}

void SetValue(NodeList *list, SpecialNode *g, SpecialNode *s){
	while(1){
		//if(getchar()== '\n')
		//{
			list->node[s->x][s->y].num = 'S';
			list->node[g->x][g->y].num = 'G';
			printf("\n\n");
			break;
		//}
	}
}
void SetStarValue(NodeList *list, SpecialNode *s){
	while(1){
		list->node[s->x][s->y].num = 'S';
		printf("\n\n");
		break;
		
	}
}
void SetOverValue(NodeList *list, SpecialNode *g){
	while(1){
		//if(getchar() == '\n'){
		list->node[g->x][g->y].num = 'G';
		printf("\n\n");
		break;
		//}
	}
}

int InputFile(NodeList *list,SpecialNode *g, SpecialNode *s){
	int x,y;
	Node node;
	FILE *fp = fopen("/home/pi/scan/s.txt", "r");
	
	if(fp == NULL) 
		return 0;
		
	for(y=0; y<MAX_Y; y++){
		for(x=0; x<MAX_X; x++)
		{
			fscanf(fp, "%c", &node.num);
			
			if(node.num == '\n'){
				fscanf(fp, "%c", &node.num);
			}
		
			
		node.x = x;
		node.y = y;
		
		list->node[x][y] = node;
		
		if(node.num == 'S'){
			s->x = x;
			s->y = y;
		}
		if(node.num == 'G'){
			g->x = x;
			g->y = y;
		}
	}
}
	fclose(fp);
	return 1;
}

int choose_next_now_node(NodeList *list, Node **now){
	int x,y;
	int temp = 10000;
	int temp_x = -1;
	int temp_y = -1;
	
	for(y=(*now)->y-1; y<=(*now)->y+1; y++)
	{
		for(x=(*now)->x-1; x<=(*now)->x+1; x++)
		{
			if(x==(*now)->x && y==(*now)->y)
			continue;
			if(list->node[x][y].openlist == open)
			{
				if(list->node[x][y].s < temp)
				{
					temp = list->node[x][y].s;
					temp_x = x;
					temp_y = y;
				}
			}
		}
	}
	if(temp_x == -1 || temp_y == -1) return 0;
	else
	{
		*now = &(list->node[temp_x][temp_y]);
		return 1;
	}
}

void Add_to_list(Node *listnode,Node node){
	listnode->s = node.s;
	listnode->g = node.g;
	listnode->h = node.h;
	listnode->openlist = open;
}
		
void OutputFile(NodeList *list, Node *now){
	FILE *fp = fopen("/home/pi/scan/result1.txt", "w");
	while(now->num != 'S')
	{
		now->num = '*';
		now = now->link;
	}
	int x,y;
	for(y=0; y<MAX_Y; y++){
		for(x=0; x<MAX_X; x++){
			fprintf(fp, "%c",list->node[x][y].num);
		}
		fprintf(fp, "%c", '\n');
	}

	fclose(fp);
}
void Display(const NodeList *list){
	int i,j;
	for(i=0;i<MAX_Y;i++){
		for(j=0;j<MAX_X;j++)
		{
			if(list->node[j][i].num == '*'){
				printf("\033[0;33;40m%c\033[0m",list->node[j][i].num);}
			else if(list->node[j][i].num == 'S'){
				printf("\033[4;32;40m%c\033[0m", list->node[j][i].num);}
			else if (list->node[j][i].num == '-' || list->node[j][i].num =='|')
				printf("\033[0;31;40m%c\033[0m", list->node[j][i].num);
			else if (list->node[j][i].num == 'G')
				printf("\033[4;36;40m%c\033[0m",list->node[j][i].num);
			else{
			printf("%c", list->node[j][i].num);}
		}
		putchar('\n');
	}
}		

void delay(int sec){
	int start=clock();
	int end;
	while(1){
		end=clock();
		if(((end-start)/1000.)>=sec){
			return;
		}
	}
}


int main(int argc,char *argv[]){
	
	int i,j;
	Node node;
	Node *temp;
	Node *now;
	SpecialNode g;
	SpecialNode s;
	NodeList list;
	
	//printf("%c %c",argv[1],argv[2]);
	//printf("%d ",argc);
	s.x = atoi(argv[1]);
    s.y = atoi(argv[2]);

	//g.x = atoi(argv[3]);
	//g.y = atoi(argv[4]); 

	//s.x = 1;
	//s.y = 1;
	g.x = 46;
	g.y = 22;

	if(InputFile(&list, &g, &s) == 0)
	{
		printf("Cannot Open File!");
		exit(1);
	}
	SetStarValue(&list,&s);
	Display(&list);
	delay(4000);
	SetOverValue(&list,&g);
	Display(&list);	
	delay(2000);
	SetValue(&list, &g, &s);
	now = &(list.node[s.x][s.y]);
	now->x = s.x;
	now->y = s.y;
	
	while(1)
	{
		now->openlist = close;
		for(i=now->y-1; i<=now->y+1; i++)
		{
			for(j=now->x-1; j<=now->x+1; j++)
			{
				if(j == now->x && i ==now->y)
					continue;
				if(list.node[j][i].num != '0' && list.node[j][i].openlist == none && list.node[j][i].num != '-' && list.node[j][i].num != '|' && list.node[j][i].num != '3' && list.node[j][i].num != '0' && list.node[j][i].num != '4' && list.node[j][i].num != 'E' && list.node[j][i].num != 'H' && list.node[j][i].num != 'C' && list.node[j][i].num != 'L' && list.node[j][i].num != '6' && list.node[j][i].num != 'I' && list.node[j][i].num != 'u' )
				{
					cal(&node, now , g , i , j);
					Add_to_list(&(list.node[j][i]),node);
					list.node[j][i].link = now;
				}
			}
		}
		
		if(list.node[g.x][g.y].s != 0) break;
		
		temp = now;
		if(choose_next_now_node(&list,&now) == 0)
		{
			now = now->pre;
			
			if(now->x == s.x && now->y == s.y)
			{
				printf("Cannot Arrive destination!\n");
				break;
			}
			continue;
		}
		else
		{
			now->pre = temp;
		}
		
	}
	OutputFile(&list,now);
	Display(&list);
	

	return 0;
}
