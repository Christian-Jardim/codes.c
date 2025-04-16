enum tipo {hortifruti=1,bebidas,mercearia,higiene,acougue,laticineos,frios,doces,padaria};

typedef struct {
	char nome[15];
	enum tipo setor;
	int quant;
	float valor;
} Item;

void menu();
Item *realocar(Item *item);
int insere(Item *item, int qt, int cont);
void apresenta(Item *item, int qt);
void apresenta1(Item *item, int qt);
void apresentaT(Item *item, int qt);
float balanco(int i, int qt, Item *item, int vt);
void buscaN(Item *item, int qt);
void buscaS(Item *item, int qt);
void venda(Item *item, int qt);
int carrega(Item *item);
int gera(int qt, Item *item);
