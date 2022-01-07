/*
 * MIT License
 * Copyright (c) 2017 Luigi Capogrosso
 *
 * This program, "detab" replaces the tabs of an input file with a
 * number of blanks spaces witch are specified by the user.
 *
 * usage: ./a.out <tabsize> <files...>
 */

// =============================================================================
#include <stdio.h>
#include <stdlib.h>

#define TEMP_FILE "./detab.temp"
// =============================================================================
int detab(int tabsize, char *file);
int text_stats(char *file);
// =============================================================================
int main(int argc, char **argv)
{
	int i, tabsize;

	if (argc != 3) {
		printf("Usage: ./a.out <tabsize> <files...>\n");
		return -1;
	}

	tabsize = atoi(argv[1]);

	if (tabsize < 1) {
		printf("Tabsize must be greater than 0!\n");
		return -1;
	}

	if (tabsize == 'a' - 'z') {
		printf("Tabsize it can't be a letter!\n");
		return -1;
	}

	for (i = 2; i < argc; i++) {
		text_stats(argv[i]);
		detab(tabsize, argv[i]);
		text_stats(argv[i]);
	}

	return 0;
}
// =============================================================================
int detab(int tabsize, char *file)
{
	int i, ch, res, pos = 0;
	FILE *fp1;
	FILE *fp2;

	fp1 = fopen(file, "r");
	printf("\n%s - opening..\n", file);

	if (fp1 == NULL) {
		printf("%s - error1!\n", file);
		return -1;
	}

	fp2 = fopen(TEMP_FILE, "w");
	printf("\n%s - opening..\n", TEMP_FILE);

	if (fp2 == NULL) {
		printf("%s - error2!\n", TEMP_FILE);
		fclose(fp1);
		return -1;
	}

	printf("\nConvert the tabs in spaces..\n");

	while ((ch = fgetc(fp1)) != EOF) {
		switch (ch) {
		case '\t':
			for (i = tabsize - pos % tabsize; --i >= 0; )
				fputc(' ', fp2);
			pos = 0;
			break;
		case '\n':
			fputc(ch, fp2);
			pos = 0;
			break;
		default:
			fputc(ch, fp2);
			pos += 1;
			break;
		}
	}

	fclose(fp1);
	fclose(fp2);

	fp1 = fopen(file, "w");
	if (fp1 == NULL) {
		printf("%s - error!\n", file);
		return -1;
	}

	fp2 = fopen(TEMP_FILE, "r");
	if (fp2 == NULL) {
		printf("%s - error!\n", TEMP_FILE);
		fclose(fp1);
		return -1;
	}

	while ((ch = fgetc(fp2)) != EOF) {
		fputc(ch, fp1);
	}

	fclose(fp1);
	fclose(fp2);

	res = remove(TEMP_FILE);
	if (res != 0) {
		printf("%s - error!\n", TEMP_FILE);
		return -1;
	}

	return 0;
}
// =============================================================================
int text_stats(char *file)
{
	int i, ch, res, pos = 0;
	FILE *fp1;

	fp1 = fopen(file, "r");
	printf("\n%s - opening..\n", file);

	if (fp1 == NULL) {
		printf("%s - error!\n", file);
		return -1;
	}

	while ((ch = fgetc(fp1)) != EOF) {
		if (ch == '\n') {
			nl += 1;
		}
		if (ch == '\t') {
			nt += 1;
		}
		if (ch == ' ') {
			ns += 1;
		}
	}

	printf("Blanks: %i\nTabs: %i\nNewlines: %i\n", ns, nt, nl);

	fclose(fp1);

	return 0;
}
