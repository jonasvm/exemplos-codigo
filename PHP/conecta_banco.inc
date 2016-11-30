<?php
     //configurações do banco de dados
     $servidor="servername";
     $usuario_bd="usuario";
     $senha_bd="senha";
     $banco="nomedobanco";
     
	 $con=mysql_connect($servidor,$usuario_bd,$senha_bd);
     mysql_select_db ($banco);
	 
	 //para encerrar a conexão
	 mysql_close($con);
?>