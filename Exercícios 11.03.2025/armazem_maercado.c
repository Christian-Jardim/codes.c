int main() {
	int cont,op,qt=0;

	printf("Insira quantos produtos serao cadastrados: ");
	scanf("%d", &cont);
	Item *item = (Item*)malloc(sizeof(Item) * cont);

	do {
		menu();
		printf("\nEscolha uma das opcoes acima: ");
		scanf("%d", &op);
		switch(op) {
		case 1:
			item = realocar(item);
			break;
		case 2:
			qt = insere(item,qt);
			break;
		case 3:
			apresenta1(item,qt);
			break;
		case 4:
			apresentaT(item,qt);
			break;
		case 5:
			balanco(qt, item);
			break;
		case 6:
			buscaN(item,qt);
			break;
		case 7:
			buscaS(item,qt);
			break;
		case 8:
			venda(item,qt);
			break;
		case 9:
		    carrega(item);
			break;
		case 10:
			gera(qt,item);
			break;
		case 11:
			free(item);
			return 0;
		}
	} while(op != 11);
}