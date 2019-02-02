<?php
/**
 * @file Copia el resultado en cac7
 */

include_once("../../etc/config.inc.php");
include_once("../../includes.php");

$query="DELETE FROM cac7; COPY cac7 FROM '/tmp/salida_cac7.csv' DELIMITER ',' CSV;";

$conn->ejecutaQuery($query);
