<?php
     if (!($bind = @ldap_bind($connect, $usr, $ pass))) {
         //se não validar
         echo “Usuário ou senha incorretos !!!”;
     } else {
         //se validar
         echo “Usuário autenticado !!!”;
     }
?>