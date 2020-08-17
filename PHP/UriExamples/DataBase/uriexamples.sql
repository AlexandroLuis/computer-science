-- phpMyAdmin SQL Dump
-- version 5.0.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Tempo de geração: 17-Ago-2020 às 22:50
-- Versão do servidor: 10.4.11-MariaDB
-- versão do PHP: 7.4.3

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Banco de dados: `uriexamples`
--

-- --------------------------------------------------------

--
-- Estrutura da tabela `exercicio`
--

CREATE TABLE `exercicio` (
  `id` int(11) NOT NULL,
  `name` varchar(15) NOT NULL,
  `class` varchar(255) NOT NULL,
  `description` varchar(255) NOT NULL,
  `type` varchar(255) NOT NULL,
  `level2pc` int(2) NOT NULL,
  `level` int(2) NOT NULL,
  `status` int(1) DEFAULT NULL,
  `Observation` varchar(255) NOT NULL,
  `source` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Extraindo dados da tabela `exercicio`
--

INSERT INTO `exercicio` (`id`, `name`, `class`, `description`, `type`, `level2pc`, `level`, `status`, `Observation`, `source`) VALUES
(0, '', 'Iniciante', '', 'E/S', 0, 0, 0, '', ' '),
(1, '', 'Nível Iniciante.', '', 'Vetores e matrizes.', 0, 0, 0, '', ' '),
(1002, 'soma impossivel', 'Geometria Comp.', 'muito dificil', 'E/S', 10, 10, 0, '', 'muito\\n\r\ndificil '),
(1004, 'Produto Simples', 'Iniciante', 'Produto de 2 valores', 'E/S', 1, 1, 0, '', 'teste\r\nteste\r\nteste\r\nteste\r\nteste\r\nteste'),
(1005, 'sem nome', 'Iniciante', 'sem descrição', 'E/S', 1, 2, 0, '', ' cdbdfbdf\r\ndfhdfj'),
(1007, 'Bubble Sort', 'AEd', 'forma de ordenação', 'Repetição', 5, 7, 0, '', ' #include <stdio.h>\r\n#include <stdlib.h>\r\n\r\nint main()\r\n{\r\n    const int N = 5;\r\n    int v[]= {9, 8, 4, 6, 3}, i, j, aux = 0;\r\n\r\n    for(i = 0; i < N; i++)\r\n        printf(\"%d	\", v[i]);\r\n\r\n     printf(\"\r\n\");\r\n\r\n    for(i = 0; i < N-1; i++)\r\n    {\r\n\r\n        for(j = 0; j < N-1- i; j++)\r\n        {\r\n            if(v[j] > v[j+1])\r\n            {\r\n                aux = v[j];\r\n                v[j] = v[j+1];\r\n                v[j+1] = aux;\r\n            }\r\n        }\r\n    }\r\n\r\n    for(i = 0; i < N; i++)\r\n        printf(\"%d	\", v[i]);\r\n}'),
(1010, 'bvbsd', 'Grafo', 'bdfzbdf', 'Repetição', 0, 0, 0, '', ' bfdhfdhdf\r\nfdgdfhfdh\r\nfdhdfhdfhdf\r\nhfdhfdhfdhdfh\r\nfdhfdhdf\r\nhfdhdfhdf\r\nhfdhdfhdfhdfhfd\r\n'),
(1050, 'NomeNome', 'Alg & data struct.', 'hahaha', 'Repetição', 5, 3, 0, 'sem muitas observações', ' codigo\r\nlinha2\r\nhahaha'),
(4565, 'asdfghjkloinmbv', 'Iniciante', 'asdfghjkloinmbvasdfghjkloinmbvkjgrtmljht', 'E/S', 7, 2, 0, '', ' asdfghjkloinmbv'),
(5465, 'fdndgnncvbn', 'Iniciante', 'vcncvnvcn', 'E/S', 6, 6, 0, '', ' hgfjhgfj\r\ngfjgfjfg\r\njgfjgfgf\r\njgfgfjsfg\r\nggncvbnxvcn\r\ncvmnbcmxbv'),
(7576, 'asdfghjkloiuytr', 'Geometria Comp.', 'asdfghjkloiuytrasdfghjkloiuytrjhytbcfepk', 'Vetores e matrizes', 10, 10, 0, '', 'asdfghjkloiuytr\r\nasdfghjkloiuytr\r\nasdfghjkloiuytr\r\nasdfghjkloiuytr\r\nasdfghjkloiuytr\r\nasdfghjkloiuytr\r\nasdfghjkloiuytr\r\nasdfghjkloiuytr\r\nasdfghjkloiuytr\r\nasdfghjkloiuytr\r\n; ');

-- --------------------------------------------------------

--
-- Estrutura da tabela `usuario`
--

CREATE TABLE `usuario` (
  `usuario_id` int(11) NOT NULL,
  `usuario` varchar(200) NOT NULL,
  `senha` varchar(32) NOT NULL,
  `Acesso` int(1) DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Extraindo dados da tabela `usuario`
--

INSERT INTO `usuario` (`usuario_id`, `usuario`, `senha`, `Acesso`) VALUES
(1, 'Admin', '202cb962ac59075b964b07152d234b70', 1),
(2, 'user', '202cb962ac59075b964b07152d234b70', 0);

--
-- Índices para tabelas despejadas
--

--
-- Índices para tabela `exercicio`
--
ALTER TABLE `exercicio`
  ADD PRIMARY KEY (`id`);

--
-- Índices para tabela `usuario`
--
ALTER TABLE `usuario`
  ADD PRIMARY KEY (`usuario_id`);

--
-- AUTO_INCREMENT de tabelas despejadas
--

--
-- AUTO_INCREMENT de tabela `usuario`
--
ALTER TABLE `usuario`
  MODIFY `usuario_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
