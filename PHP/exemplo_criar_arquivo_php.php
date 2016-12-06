<?php
     $arquivo = "teste.txt";
     $conteudo = "conteudodoarquivo 2123123";
     $texto = "$arquivo";
     $abrearquivo = fopen($texto, 'w');
     fwrite($abrearquivo, $conteudo);
     fclose($abrearquivo);
?>