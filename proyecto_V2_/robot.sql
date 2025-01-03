-- phpMyAdmin SQL Dump
-- version 5.1.1
-- https://www.phpmyadmin.net/
--
-- Servidor: 127.0.0.1
-- Tiempo de generación: 21-12-2021 a las 19:30:20
-- Versión del servidor: 10.4.22-MariaDB
-- Versión de PHP: 7.3.33

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de datos: `robot`
--

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `posicionmotores`
--

CREATE TABLE `posicionmotores` (
  `numero` int(11) NOT NULL,
  `motor_0` varchar(4) DEFAULT NULL,
  `motor_1` varchar(4) DEFAULT NULL,
  `motor_2` varchar(4) DEFAULT NULL,
  `motor_3` varchar(4) DEFAULT NULL,
  `motor_4` varchar(4) DEFAULT NULL,
  `motor_5` varchar(4) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Volcado de datos para la tabla `posicionmotores`
--

INSERT INTO `posicionmotores` (`numero`, `motor_0`, `motor_1`, `motor_2`, `motor_3`, `motor_4`, `motor_5`) VALUES
(3, '70', '133', '122', '0', '55', '160'),
(4, '70', '120', '115', '0', '55', '160'),
(5, '70', '133', '122', '0', '55', '90'),
(6, '70', '110', '122', '0', '55', '90'),
(7, '180', '115', '122', '0', '55', '90'),
(8, '180', '125', '122', '0', '40', '160'),
(10, '168', '115', '122', '0', '55', '90'),
(11, '168', '125', '122', '0', '55', '160'),
(12, '159', '115', '122', '0', '70', '90'),
(13, '159', '125', '122', '0', '70', '160'),
(14, '30', '110', '45', '0', '70', '45'),
(15, '70', '133', '122', '0', '55', '120'),
(16, '70', '110', '122', '0', '55', '120'),
(20, '140', '110', '122', '0', '82', '120'),
(21, '140', '120', '122', '0', '82', '160'),
(22, '130', '120', '122', '10', '100', '120'),
(23, '130', '125', '122', '10', '100', '160'),
(24, '120', '127', '122', '20', '110', '120'),
(25, '120', '130', '122', '20', '110', '160');

--
-- Índices para tablas volcadas
--

--
-- Indices de la tabla `posicionmotores`
--
ALTER TABLE `posicionmotores`
  ADD PRIMARY KEY (`numero`);

--
-- AUTO_INCREMENT de las tablas volcadas
--

--
-- AUTO_INCREMENT de la tabla `posicionmotores`
--
ALTER TABLE `posicionmotores`
  MODIFY `numero` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=26;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
