<?php
     //exemplo abrindo  Notepad
     exec('notepad');
	 
	 //exemplo abrindo a Calculadora 
     exec('calc');

	 //exemplo de uma sequencia usando o exec
     exec ("teste.bat");
     $redirecionar = "http://seusite";
     header("Location: $redirecionar");
?>