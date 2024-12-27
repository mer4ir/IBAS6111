#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
int probsogl(char* s, int i, int b, int f, char* r)
{
	if (s[i] == 'b') { //b
		if (i+1 == f){}
		else strcat(r, "б");
	}
	if (s[i] == 'c') { //c
		if (strchr("iye", s[i + 1])) {//ci,cy,ce
			strcat(r, "с"); return i;
		}
		if (s[i + 1] == 'i' && s[i + 2] == 'a') { //cia
			strcat(r, "шиа"); i+=2; return i;
		}
		if (s[i+1] == 'k') { //ck
			strcat(r, "к"); i++; return i;
		}
		if (s[i + 1] == 'h') {//ch
			if (s[i + 2] == 'r') { //chr
				strcat(r, "кр"); i+=2; return i;
			}
			else { //ch
				strcat(r, "ч"); i++; return i;
			}
		}
		else strcat(r, "к");
	}
	if (s[i] == 'd') strcat(r, "д"); //d
	if (s[i] == 'f') strcat(r, "ф"); //f
	if (s[i] == 'g') { //g
		if (strchr("iye", s[i + 1])) strcat(r, "дж"); //gi,gy,ge
		if (s[i + 1] == 'h') { //gh
			if ((s[i + 2] ==  't') || (i + 2 == f)) {
			}
			else {
				strcat(r, "гх");
			}
			i++;
			return i;
		}
		else strcat(r, "г"); //g
	}
	if (s[i] == 'h') strcat(r, "х"); //h
	if (s[i] == 'j') strcat(r, "дж"); //j
	if (s[i] == 'l') strcat(r, "л"); //l
	if (s[i] == 'k') { //k
		if (i == b && s[i + 1] == 'n') {} //kn
		else strcat(r, "к"); //k
	}
	if (s[i] == 'm') strcat(r, "м"); //m
	if (s[i] == 'n') strcat(r, "н"); //n
	if (s[i] == 'p') { //p
		if (s[i + 1] == 'h' && i == b) {
			strcat(r, "ф"); i++; return i;
		}
		else strcat(r, "п");
	}
	if (s[i] == 'q') strcat(r, "к"); //q
	if (s[i] == 'r') strcat(r, "р"); //r
	if (s[i] == 's') { //s
		if (s[i + 1] == 'h') {
			strcat(r, "ш"); i++; return i;
		}
		if (s[i + 1] == 'u') {
			if (i == b) strcat(r, "ш");
			else strcat(r, "ж");
		}
		else strcat(r, "с");
	}
	if (s[i] == 't') { //t
		if (f - i == 4) {
			if (s[i + 1] == 'u' && s[i + 2] == 'r' && s[i + 3] == 'e') {
				strcat(r, "чер"); i += 3; return i;
			}
			if (s[i + 1] == 'i' && s[i + 2] == 'o' && s[i + 3] == 'n') {
				strcat(r, "шен"); i += 3; return i;
			}
		}
		if (s[i + 1] == 'z') {
			strcat(r, "ц"); i++; return i;
		}
		if (s[i + 1] == 'h') {
			if (s[i + 2] == 'e') {
				strcat(r, "зе"); i += 2; return i;
			}
			else {
				strcat(r, "т"); i++; return i;
			}
		}
		else strcat(r, "т");
	}
	if (s[i] == 'v') strcat(r, "в"); //v
	if (s[i] == 'w') { //w
		if (s[i + 1] == 'h') {
			strcat(r, "у"); i++; return i;
		}
		if (s[i + 1] == 'o' && s[i + 2] == 'r') {
			strcat(r, "уор"); i += 2; return i;
		}
		else strcat(r, "в");
	}
	if (s[i] == 'x') strcat(r, "кс"); //х
	if (s[i] == 'z') strcat(r, "з"); //z
	return i;
}

int probgl(char* s, int i, int b, int f, char* r) {
	if (s[i] == 'a') { //a
		if (s[i + 1] == 'i' || s[i + 1] == 'y') {
			strcat(r, "эй"); i++; return i;
		}
		if (s[i + 1] == 'r' && s[i + 2] == 'e') {
			strcat(r, "ар"); i+=2; return i;
		}
		if (s[i + 1] == 'u' && s[i + 2] == 'w') {
			strcat(r, "о"); i++; return i;
		}
		else strcat(r, "а");
	}
	if (s[i] == 'e') {
		if (s[i + 1] == 'a') {
			strcat(r, "э"); i++; return i;
		}
		if (s[i + 1] == 'e') {
			strcat(r, "и"); i++; return i;
		}
		if (s[i + 1] == 'i') {
			strcat(r, "эй"); i++; return i;
		}
		if (s[i + 1] == 'o') {
			strcat(r, "и"); i++; return i;
		}
		if (s[i + 1] == 'r') {
			strcat(r, "эр"); i++; return i;
		}
		if (s[i + 1] == 'r' && s[i+2] == 'e') {
			strcat(r, "эр"); i+=2; return i;
		}
		if (s[i + 1] == 'u' || s[i + 1] == 'w') {
			strcat(r, "у"); i++; return i;
		}
		if (s[i + 1] == 'y') {
			strcat(r, "эй"); i++; return i;
		}
		else strcat(r, "е");
	}
	if (s[i] == 'i') { //i
		if (s[i + 1] == 'a') {
			strcat(r, "айа"); i++; return i;
		}
		if (s[i + 1] == 'e') {
			strcat(r, "и"); i++; return i;
		}
		if (s[i + 1] == 'o') {
			strcat(r, "айо"); i++; return i;
		}
		if (s[i + 1] == 'r' && s[i + 2] == 'e') {
			strcat(r, "айр"); i+=2; return i;
		}
	else strcat(r, "и");
	}
	if (s[i] == 'o') { //o
		if (s[i + 1] == 'i' || s[i + 1] == 'y') { //oi, oy
			strcat(r, "ой"); i++; return i;
		}
		if (s[i + 1] == 'e') { //oe
			strcat(r, "и"); i++; return i;
		}
		if (s[i + 1] == 'o') { //oo
			if (s[i + 2] == 'r') { //oor
				strcat(r, "ор"); i += 2; return i;
			}
			else { //oo
				strcat(r, "у"); i++; return i;
			}
		}
		if (s[i + 1] == 'u') { //ou
			if (s[i + 2] == 'r') { //our
				strcat(r, "аур"); i += 2; return i;
			}
			else { //ou
				strcat(r, "у"); i++; return i;
			}
		}
		if (s[i + 1] == 'a') { //oa
			strcat(r, "о"); i++; return i;
		}
		if (s[i + 1] == 'w') { //ow
			strcat(r, "ау"); i++; return i;
		}
		else strcat(r, "о"); //o
	}
	if (s[i] == 'u') { //u
		if (s[i + 1] == 'e') { //ue
			strcat(r, "е"); i++; return i;
		}
		if (s[i+1] == 'i') { //ui
			strcat(r, "и"); i++; return i;
		}
		if (s[i + 1] == 'r') { //ur
			strcat(r, "эр"); i++; return i;
		}
		else strcat(r, "у");
	}
	if (s[i] == 'y') { //y
		if (i == b) strcat(r, "й");
		if (i+1 == f) strcat(r, "и");
		else strcat(r, "ай");
	}
	return i;
}

void probdeli(char* s, int i, char* r) {
	if (s[i] == ' ') strcat(r, " ");
	if (s[i] == ',') strcat(r, ",");
	if (s[i] == '.') strcat(r, ".");
	if (s[i] == '!') strcat(r, "!");
	if (s[i] == '?') strcat(r, "?");
	if (s[i] == ';') strcat(r, ";");
	if (s[i] == '\n') strcat(r, "\n");
	if (s[i] == '\'') strcat(r, "\"");
	if (s[i] == '-') strcat(r, "-");
}

void scan(char* s)
{
	char r[256] = { "\0" };
	char delimeters[] = " .,;!?\"\'-\n", g[] = "eyuioa", sog[] = "bcdfghjlkmnpqrstvwxz";
	int i = 0, e = 0; //i - текущий индекс
	while (s[e] != '\0') e++;
	while (i < e)
	{
		while (strchr(delimeters, s[i])) {
			probdeli(s,i,r); i++;
		}
		int b = i, f = i; //b - начало слова, а - символ после конца слова, 
		while (strchr(delimeters, s[f]) == 0) f++;
		while (s[i] != s[f])
		{
			if ((strchr(g, s[i]))) i = probgl(s, i, b, f, r);
			else i = probsogl(s, i, b, f, r);
			i++;
		}
	}
	puts(r);
}

int main()
{
	setlocale(LC_ALL, "RUS");
	char str[256];
	fgets(str, 256, stdin);
	str[strlen(str)-1] = ' ';
	for (int i = 0; str[i]; i++) {
		str[i] = tolower(str[i]);
	}
	scan(str);
	return 0;
}
