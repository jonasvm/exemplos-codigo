<?php
     //obtendo os dados do usuário
     $username = $_POST["username"];
     $senha = $_POST["senha"];

	 //acesso ao bd
     include "conecta_mysql.inc";
     $resultado = mysql_query("SELECT username,senha,id FROM usuarios where username='$username'") or die(mysql_error());
     $linhas = mysql_num_rows($resultado);
     $row=mysql_fetch_array($resultado);
     $id = $row['id'];
     if($linhas == 0)
     {
          echo "<html><body>";
          echo "<p>Usuário não encontrado!</p>";
          echo "<a href=index.htm>Voltar</a>";
          echo "</body></html>";
     }else
     {
          if($senha != mysql_result($resultado, 0, "senha"))
          {
               echo "<html><body>";
               echo "<p>A senha está incorreta!</p>";
               echo "<a href=index.htm>Voltar</a>";
               echo "</body></html>";
          }
          else
          {
               session_start();
               $_SESSION["nome_usuario"] = $username;
               $_SESSION["senha_usuario"] = $senha;
               $_SESSION["id"] = $id;
               header("Location: index.htm");
          }
     }

	 mysql_close($con);
?>