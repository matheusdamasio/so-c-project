# so-c-project
Projeto de SO 
Fontes:
https://brizeno.wordpress.com/2011/09/25/praticando-concorrencia-em-java-semaforos/
http://tutorials.jenkov.com/java-concurrency/semaphores.html
http://www.ece.ufrgs.br/~fetter/eng04008/sem.pdf
http://www.dca.fee.unicamp.br/~lotufo/cursos/EA877/sistemas-operacionais/exemplos/semaforo.c


Execucao em Java:
Caso de Sucesso: Quando nenhum jogador começa a jogar no turno do outro, ou seja, o jogador começa o turno e termina sem ser interrompido.
Situação de falha: as threads são acordadas aleatóriamente, embaralhando podendo embaralhar a execução. Outro caso de falha, este exemplo pode não resolver a condição de corrida pois, mais de uma thread pode acessar a região criítica de uma vez, se for manipulado o número de permissões.
Onde foi a execução: Windows 7 amd64 , NetBeans versão 8.0.2, java versão 8.
Como executar: 
Através do terminal, ir navegando através do comando 'cd' para a pasta em que o objeto se encontra após o download, após chegar na pasta, basta executar o seguinte comando: java -jar ProjetoSO.jar

Caso queira, descompactar o projeto e executar através do netbeans.

Execuçao em C: 
Caso de sucesso: mostrar os dados escritos em tela.
Caso de falha: 
Como executar: em linux, usando o terminal, compile o arquivo projetoso.c (gcc -o projetoso.bin projetoso.c) e execute para verificar o resultado.
