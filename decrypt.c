#include <qc_mdpc.h>
#include <matrix.h>
#include <mceliece.h>
#include <stdlib.h>
#include <stdio.h>
#include <argv.h>


int main(int argc, char const *argv[])
{
	int n0, p, w, t;
    n0 = atoi(get_argv(argc, argv, "-n0"));
    p = atoi(get_argv(argc, argv, "-p"));
    w = atoi(get_argv(argc, argv, "-w"));
    t = atoi(get_argv(argc, argv, "-t"));
	int k = (n0 - 1) * p;
	printf("Enter code of length %d: \n", k);
	unsigned short inp;
	bin_matrix msg = mat_init(1, k);
	for(int i = 0; i < k; i++)
	{
		scanf("%hu", &inp);
		set_matrix_element(msg, 0, i, inp);
	}
	mcc crypt = mceliece_init(n0, p, w, t);
	bin_matrix m = decrypt(msg, crypt);
	
	FILE *fp1;
	fp1 = fopen("Decryption.txt", "w");
	fprintf(fp1, "Decrypted message: \n");
	for(int i = 0; i < m->cols; i++)
	{
		fprintf(fp1, "%hu ", get_matrix_element(m, 0, i));
	}
	fclose(fp1);

	return 0;
}