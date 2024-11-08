// Viết một function makeDrink
void makeDrink(int drink)
{
	switch (drink)
	{
	case 0:
		printf("canceled oder!\n");
		break;
	case 1:
		printf("make a cup of cafe\n");
		break;
	case 2:
		printf("make a cup of milk tea\n");
		break;
	default:
		printf("Dunno how to make this drink\n");
	}
}

int main()
{
	int drink = 0;
	printf("select a drink from the menu\n");
	printf("0: cancel\n");
	printf("1: cafe\n");
	printf("2: milk tea\n");
	printf("My choice: ");
	scanf("%d", &drink);
	makeDrink(drink);
}

// ------------------ REFRACTOR CODE WITH FUNCTIOn POINTER -----------------

void cancelOrder()
{
	printf("Canceled order!\n");
}
void makeCafe()
{
	printf("Make a cup of cafe\n");
}
void makeMilkTea()
{
	printf("Make a cup of milk tea\n");
}

typedef void (*MakeDrinkFn)();

MakeDrinkFn menu[3] = {
	cancelOrder,
	makeCafe,
	makeMilkTea};

int main() {
	int drink = 0;
	printf("Select a drink from the menu\n");
	printf("e: Cancel\n");
	printf("1: Cafein\n");
	printf("2: Tà tựa\n");
	printf("My choice: );
	scanf("%d", &drink);

	if (drink < 3)
		menu[drink]();
	else
		printf("Dunno how to make this drink\n");
}
