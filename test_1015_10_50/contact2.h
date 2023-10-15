#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

typedef struct People
{
	char name[20];
	int age;
	char sex[5];
	char tele[12];
	char addr[30];
}peo;

//typedef struct Contact
//{
//	peo data[1000];
//	int sz;
//}con;

typedef struct Contact
{
	peo* data;
	int sz;
	int capacity;
}con;

void InitContact(con* c);
void AddContact(con* c);
void ShowContact(con* c);
void DelContact(con* c);
void SearchContact(con* c);
void ModContact(con* c);
void CleContact(con* c);
void SortContact(con* c);
//void DestroyContact(con* c);
void SaveContact(con* c);

void LoadContact(con* c);
