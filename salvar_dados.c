#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

int main() {
    MYSQL *con = mysql_init(NULL);
    if (con == NULL) {
        fprintf(stderr, "%s\n", mysql_error(con));
        exit(1);
    }

    if (mysql_real_connect(con, "localhost", "usuario", "senha", "nome_do_banco", 0, NULL, 0) == NULL) {
        fprintf(stderr, "%s\n", mysql_error(con));
        mysql_close(con);
        exit(1);
    }

    if (mysql_query(con, "CREATE TABLE IF NOT EXISTS Contatos (id INT AUTO_INCREMENT PRIMARY KEY, nome VARCHAR(100), email VARCHAR(100), assunto VARCHAR(100), descricao TEXT)")) {
        fprintf(stderr, "%s\n", mysql_error(con));
        mysql_close(con);
        exit(1);
    }

    char nome[100], email[100], assunto[100], descricao[1000];

    printf("Nome: ");
    scanf("%s", nome);

    printf("Email: ");
    scanf("%s", email);

    printf("Assunto: ");
    scanf("%s", assunto);

    printf("Descrição: ");
    scanf("%s", descricao);

    char query[1500];
    sprintf(query, "INSERT INTO Contatos (nome, email, assunto, descricao) VALUES ('%s', '%s', '%s', '%s')", nome, email, assunto, descricao);

    if (mysql_query(con, query)) {
        fprintf(stderr, "%s\n", mysql_error(con));
        mysql_close(con);
        exit(1);
    }

    printf("Dados inseridos com sucesso!\n");

    mysql_close(con);
    return 0;
}
