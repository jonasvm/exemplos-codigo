<?php
     $origem = 'arquivo.txt';
     $destino = 'pasta/example.txt';
     copy($origem, $destino);
     
     //Deletar
     unlink($origem);
?>