#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayClientes.h"
#include "archivos.h"

Cliente* cli_newConParametros(int id, char* name);

int main(void)
{
	Cliente* pc1;
	Cliente* pc2;
	Cliente* pc3;

	pc1 = cli_newConParametros(1, "Pepe");
	pc2 = cli_newConParametros(2, "Juan");
	pc3 = cli_newConParametros(3, "Tani");

	printf("cliente id: %d, name: %s\n", pc1->id, pc1->name);
	printf("cliente id: %d, name: %s\n", pc2->id, pc2->name);
	printf("cliente id: %d, name: %s\n", pc3->id, pc3->name);

	escritura();
	lectura();
	escrituraDos();

	return 0;
}

Cliente* cli_newConParametros(int id, char* name)
{
	Cliente* pc = NULL;
	if(id>0 && name!=NULL)
	{
		pc = (Cliente*)malloc(sizeof(Cliente));
		if(pc!=NULL)
		{
			pc->id= id;
			strncpy(pc->name,name,sizeof(pc->name));
		}
	}
	return pc;
}
