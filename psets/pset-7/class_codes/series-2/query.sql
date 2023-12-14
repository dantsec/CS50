-- [ INIT ]
-- configurando nosso bd
.mode csv
.import [CSV_FILE] [TABLE_NAME]

-- ver como esta montado o bd
.schema

-- vendo tempo de query (ligando e desligando funcao)
.timer [ON / OFF]

-- [ CRUD ]
-- [c]reate - criar tabelas ;; inserindo valores
CREATE TABLE [TABLE_NAME] ([COLUMN] [TYPE], ...);
INSERT INTO [TABLE_NAME] ([COLUMN], ...) VALUES([VALUE], ...);

-- [r]ead - ler dados
SELECT [ [COLUMNS] / [*] ] FROM [TABLE_NAME];

-- [u]pdate - alterar dados
UPDATE [TABLE_NAME] SET [COLUMNS] WHERE [COMPARE_PARAM];

-- [d]elete - exclusao de dados
DELETE FROM [TABLE_NAME] WHERE [COMPARE_PARAM];

-- [ TIPOS DE DADOS / JARGOES ]
-- BLOB (Binary Logic OBject), INTEGER (smallint / integer / bigint), NUMERIC (booleano, data, data-tempo, tempo), REAL (real, double precision), TEXT (char, varchar, text)
-- NOT NULL, UNIQUE
-- PRIMARY KEY (PK) & FOREIGN KEY (FK )

-- [ EVITANDO RACE CONDITIONS ]
BEGIN TRANSACTION
-- ...
COMMIT

-- [ OUTROS ]
-- importantes: AVG, COUNT, DISTINCT, LOWER, MAX, MIN, UPPER ;; WHERE, LIKE, ORDER BY, LIMIT, GROUP BY

-- fazendo buscas usando JOIN
-- as duas consultas sao IGUAIS, porem uma tem `interface` mais amigavel
SELECT title FROM shows WHERE id IN (SELECT show_id FROM stars WHERE person_id = (SELECT id FROM people WHERE name = "Steve Carell"));
-- para poder deixar mais rapida
CREATE INDEX person_index ON stars (person_id);
CREATE INDEX show_index ON stars (show_id);
CREATE INDEX name_index ON people (name);
--
SELECT title FROM people JOIN stars ON people.id = stars.person_id JOIN shows ON stars.show_id = shows.id WHERE name = "Steve Carell";

-- pega apenas dados unicos
SELECT DISTINCT(title) FROM shows;
-- coloca os nomes em maiusculo
SELECT DISTINCT(UPPER(title)) FROM shows;
-- procura por um dado especifico
SELECT title FROM shows WHERE title = "The Office";
SELECT title FROM shows WHERE title LIKE "%Office%";
-- ordena em ordem alfabetica
SELECT DISTINCT(UPPER(title)) FROM shows ORDER BY UPPER(title);
-- retorna a quantidade de dados da tabela
SELECT COUNT(*) FROM title;
-- ordena em ordem alfabetica da forma [titulo],[num_aparicoes]
SELECT UPPER(title), COUNT(title) FROM shows GROUP BY UPPER(title);
-- ordem alfabetica + [titulo],[num_aparicoes] (agora com a entrara `title` mais tratada)
SELECT UPPER(TRIM(title)), COUNT(title) FROM shows GROUP BY UPPER(TRIM(title)) ORDER BY COUNT(title) DESC LIMIT 10;
-- retorna quantos titulos `X` aparecem como TRUE na comparacao
SELECT COUNT(title) FROM shows WHERE title LIKE "Friends";
-- usamos IN para consultar entre duas tabelas (a partir dos estilos -> temos os filmes)
SELECT title FROM shows WHERE id IN (SELECT show_id FROM genres WHERE genre = "Musical");
-- a partir do filme -> temos os estilos + ordem alfabetica
SELECT DISTINCT(genre) FROM genres WHERE show_id IN (SELECT id FROM shows WHERE title = "THE OFFICE") ORDER BY genre;
