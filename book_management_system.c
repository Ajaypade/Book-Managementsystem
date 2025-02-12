#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct book
{
	int id;
	char Book_name[50];
	char Author_name[50];
	char category[50];
	float price;
	int rating;
}book;

void addbooks(book*, int*);
void removebooks(book*, int*);
void searchbooks(book*, int);
void showauthorsbooks(book*, int);
void showcategorysbooks(book*, int);
void updatebookdata(book*, int);
void display(book*, int*);
void displayallbooks(book*, int*);
void displaypricesortedbooks(book*, int*);
void displayratingsortedbooks(book*, int*);

void main()
{
	int size = 0;
	book* arr = (book*)malloc(sizeof(book));
	int choice;
	do
	{
		printf("\n\t1.Add Books :");
		printf("\n\t2.Remove Books :");
		printf("\n\t3.Search Books :");
		printf("\n\t4.Show Authors Book :");
		printf("\n\t5.Show Categorys Book :");
		printf("\n\t6.Update Book Data :");
		printf("\n\t7.Display :");
		printf("\n\t0.exit :");
		printf("\n---------------------------------------------------------\n");
		printf("\nEnter your choice: ");
		scanf("%d", &choice);

		switch (choice)
		{
			case 1:
				addbooks(arr, &size);
				break;
			case 2:
				removebooks(arr, &size);
				break;
			case 3:
				searchbooks(arr, size);
				break;
			case 4:
				showauthorsbooks(arr, size);
				break;
			case 5:
				showcategorysbooks(arr, size);
				break;
			case 6:
				updatebookdata(arr, size);
				break;
			case 7:
				display(arr, &size);
				break;
			case 0:
				exit(0);
			default:
				printf("\nInvalid choice!\n");
				break;
		}
	} 
	while (choice != 0);
}

void addbooks(book* arr, int* size)
{
	arr = (book*)realloc(arr, (*size + 1) * sizeof(book));
	 
	printf("\n\tBook id :");
	scanf("%d", &arr[*size].id);
	fflush(stdin);
	printf("\tBook Name :");
	scanf("%s", arr[*size].Book_name);
	fflush(stdin);
	printf("\tAuthor Name :");
	scanf("%s", arr[*size].Author_name);
	fflush(stdin);
	printf("\tBook category :");
	scanf("%s", arr[*size].category);
	fflush(stdin);
	printf("\tBook Price :");
	scanf("%f", &arr[*size].price);
	printf("\tRating  :");
	scanf("%d", &arr[*size].rating);
	(*size)++;
	
	printf("\nBook Data Added Successfully......");
	printf("\n-------------------------------------------------------------\n");
}

void removebooks(book* arr, int* size)
{
	int id;
	printf("\nEnter ID to remove a book : ");
	scanf("%d", &id);
	int i, j;
	for (i = 0; i < *size; i++)
	{
		if (arr[i].id == id)
		{
			for (j = i; j < *size - 1; j++)
			{
				arr[j] = arr[j + 1];
			}
			(*size)--;
			printf("\nBook Removed Successfully.......");
			printf("\n-----------------------------------------------------------\n");
			return;
		}
	}
	printf("\nBook with ID %d not found!\n", id);
}

void searchbooks(book* arr, int size)
{
	int id;
	char bookname[50];
	printf("\nEnter id to search book :");
	scanf("%d", &id);
	printf("Enter bookname to search book :");
	scanf("%s", bookname);

	int i;
	printf("\n---------------------------------------------------------------\n");
	printf("| %-5s | %-20s | %-20s | %-15s | %-8s | %-6s |\n", "ID", "Name", "Author", "Category", "Price", "Rating");
	printf("---------------------------------------------------------------\n");
	for (i = 0; i < size; i++)
	{
		if (strcmp(arr[i].Book_name, bookname) == 0 || arr[i].id == id)
		{
			printf("| %-5d | %-20s | %-20s | %-15s | %-8.2f | %-6d |\n", 
				arr[i].id, arr[i].Book_name, arr[i].Author_name, arr[i].category, arr[i].price, arr[i].rating);
			printf("---------------------------------------------------------------\n");
			return;
		}
	}
	printf("\nBook not found!\n");
}

void showauthorsbooks(book* arr, int size)
{
	char authorname[50];
	fflush(stdin);
	printf("\nEnter author name you want to show :");
	scanf("%s", authorname);
	int i;
	printf("\nAuthor's Books are :\n");
	for (i = 0; i < size; i++)
	{
		if (strcmp(arr[i].Author_name, authorname) == 0)
		{
			printf("\tBook Name : %s\n", arr[i].Book_name);
		}
	}
	printf("\n---------------------------------------------------------------\n");
}

void showcategorysbooks(book* arr, int size)
{
	char category[50];
	fflush(stdin);
	printf("\nEnter category you want to show :");
	scanf("%s", category);
	
	int i;
	printf("\nCategory's Books are :\n");
	for (i = 0; i < size; i++)
	{
		if (strcmp(arr[i].category, category) == 0) 
		{
			printf("\tBook Name : %s\n", arr[i].Book_name);
		}
	}
	printf("\n--------------------------------------------------------------\n");
}

void updatebookdata(book* arr, int size)
{
	char update[50];
	fflush(stdin);
	printf("\nEnter the name of the book to update: ");
	scanf("%49s", update);

	int i;
	for (i = 0; i < size; i++)
	{
		if (strcmp(arr[i].Book_name, update) == 0) 
		{
			printf("\nEnter new book details:\n");
			printf("Book Price : ");
			scanf("%f", &arr[i].price);
			printf("Book Rating : ");
			scanf("%d", &arr[i].rating);
			printf("\nBook updated successfully.....\n");
			return;
		}
	}
	printf("\nBook not found!\n");
}

void display(book* arr, int* size)
{
	int choice;
	do
	{
		printf("\n\t1. Display price sorted books :");
		printf("\n\t2. Display rating sorted books :");
		printf("\n\t3. Display all books :");
		printf("\n\t0. Go back :\n");
		printf("\n\tEnter your choice : ");
		scanf("%d", &choice);

		switch (choice)
		{
			case 1:
				displaypricesortedbooks(arr, size);
				break;
			case 2:
				displayratingsortedbooks(arr, size);
				break;
			case 3:
				displayallbooks(arr, size);
				break;
			case 0:
				return;
			default:
				printf("Invalid Choice!\n");
		}
	} while (choice != 0);
}

void displayallbooks(book* arr, int* size)
{
	int i;
	printf("\nDisplay All Books : \n");
	printf("\n--------------------------------------------------------------------------------------------\n");
	printf("| %-5s | %-20s | %-20s | %-15s | %-8s | %-6s |\n", "ID", "Name", "Author", "Category", "Price", "Rating");
	printf("--------------------------------------------------------------------------------------------\n");
	for (i = 0; i < *size; i++)
	{
		printf("| %-5d | %-20s | %-20s | %-15s | %-8.2f | %-6d |\n", 
			arr[i].id, arr[i].Book_name, arr[i].Author_name, arr[i].category, arr[i].price, arr[i].rating);
	}
	printf("--------------------------------------------------------------------------------------------\n");
}

void displaypricesortedbooks(book* arr, int* size)
{
	int i, j;
	book temp;
	for (i=0 ; i < *size - 1; i++)
	{
		for (j = 0; j < *size - i - 1; j++)
		{
			if (arr[j].price < arr[j + 1].price)
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	printf("\nDisplay highest/lowest-priced Sorted Books :\n");
	printf("\n--------------------------------------------------------------------------------------------\n");
	printf("| %-5s | %-20s | %-20s | %-15s | %-8s | %-6s |\n", "ID", "Name", "Author", "Category", "Price", "Rating");
	printf("--------------------------------------------------------------------------------------------\n");
	for(i=0;i<*size;i++)
	{
		printf("| %-5d | %-20s | %-20s | %-15s | %-8.2f | %-6d |\n", 
			arr[i].id, arr[i].Book_name, arr[i].Author_name, arr[i].category, arr[i].price, arr[i].rating);
	}
	printf("--------------------------------------------------------------------------------------------\n");
}

void displayratingsortedbooks(book* arr, int* size)
{
	int i, j;
	book temp;
	for (i = 0; i < *size - 1; i++)
	{
		for (j = 0; j < *size - i - 1; j++)
		{
			if (arr[j].rating < arr[j + 1].rating)
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	printf("\nDisplay highest/lowest-rated Sorted Books :\n");
	printf("\n--------------------------------------------------------------------------------------------\n");
	printf("| %-5s | %-20s | %-20s | %-15s | %-8s | %-6s |\n", "ID", "Name", "Author", "Category", "Price", "Rating");
	printf("--------------------------------------------------------------------------------------------\n");
	for(i=0;i<*size;i++)
	{
		printf("| %-5d | %-20s | %-20s | %-15s | %-8.2f | %-6d |\n", 
			arr[i].id, arr[i].Book_name, arr[i].Author_name, arr[i].category, arr[i].price, arr[i].rating);
	}
	printf("--------------------------------------------------------------------------------------------\n");
}
