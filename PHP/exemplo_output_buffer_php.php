<?php
     //iniciamos o processo de buffering
     ob_start();
     $teste = 'teste';

	 //aqui guardamos o conteúdo da variável teste em um cookie
     setcookie("cookie_teste",$teste);

	 //encerramos o processo de bufferização porque o cookie já foi gravado.
     ob_end_clean();
?>