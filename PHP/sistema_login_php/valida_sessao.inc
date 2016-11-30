<?php
     session_start();
     if(IsSet($_SESSION["nome_usuario"]))
          $nome_usuario = $_SESSION["nome_usuario"];
     if(IsSet($_SESSION["senha_usuario"]))
          $senha_usuario = $_SESSION["senha_usuario"];
     if(!(empty($nome_usuario) OR empty($senha_usuario)))
     {
          include "conecta_mysql.inc";
          $resultado = mysql_query("SELECT * FROM usuarios WHERE username='$nome_usuario'");
          if(mysql_num_rows($resultado) == 1)
          {
               if($senha_usuario != mysql_result($resultado,0,"senha"))
               {
                    unset($_SESSION["nome_usuario"]);
                    unset($_SESSION["senha_usuario"]);
                    echo "Você não efetuou o LOGIN!";
                    echo '<br><a href="index.htm">Fazer login.</a>';
                    exit;
               }
          }
          else
          {
               unset ($_SESSION["nome_usuario"]);
               unset ($_SESSION["senha_usuario"]);
               echo "Você não efetuou o LOGIN!";
               echo '<br><a href="index.htm">Fazer login.</a>';
               exit;
          }
     }
     else
     {
          echo "Você não efetuou o LOGIN!";
          echo '<br><a href="index.htm">Fazer login.</a>';
          exit;
     }
     
	 mysql_close($con);
?>