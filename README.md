# Cpp_Project_CinemaDatabase

Neste projeto, teremos a oportunidade de aplicar os conceitos de busca e ordenação que estudamos em sala de aula na disciplina **Técnicas de Busca e Ordenação** em um cenário que simula os desafios que vocês encontrarão no futuro.

Criaremos implementações usando algoritmos de busca e ordenação para organizar uma base de dados contendo informações sobre filmes e cinemas.

## Definição

O usuário poderá utilizar procurar por filmes ou cinemas.
No caso de filme o usuário poderá utilizar os seguintes filtros:

1. Filmes de um ou mais tipos (coluna *titleType*).
2. Filmes que pertencem a um ou mais gêneros (coluna *genres*).
3. Filmes com uma duração específica entre um limite inferior e superior em
minutos.
4. Filmes lançados em um ano específico ou em um intervalo de anos.

No caso de cinema o usuário poderá utilizar os seguintes filtros:

1. Cinemas que contém filmes de um ou mais tipos (coluna *titleType*).
2. Cinemas que contém filmes que pertencem a um ou mais gêneros (coluna
*genres*).
3. Cinemas que contém filmes com uma duração específica entre um limite
inferior e superior em minutos.
4. Cinemas em uma localização de até uma distância definida de um local.
5. Cinemas com preços até um limite superior de unidades monetárias.
6. Cinemas que contém filmes lançados em um ano específico ou em um
intervalo de anos.

Em ambos os casos os filtros podem ser combinados livremente pelo usuário
utilizando os operadores lógicos "e" ou "ou".

Exemplos:

* Consultar cinemas que tenham filme de gênero "Documentary" ou "Short",
e distância de no máximo 1000 do ponto (20019, 510301), com preço na
máximo 15, 00.

* Consultar filmes do tipo "tvEpisode" feitos no ano 2004, do gênero Comedy
ou Talk-Show.

Os dados dos cinemas e filmes estarão em arquivos disponibilizados. Caso o
cinema referencie um código de filme que não existe você deve pegar o filme
com o código maior mais próximo do código do filme.

Seu trabalho deve sempre mostrar o tempo utilizado, tanto ao carregar a base de
dados, quanto ao mostrar as buscas. É preferível um tempo considerável
ao carregar, que ao consultar.

### Colaboradores

* [@AnaLuizanc](https://github.com/AnaLuizanc)
* [@T1T1R3](https://github.com/T1T1R3)