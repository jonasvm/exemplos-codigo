<?php
     if (!($connect = @ldap_connect('ldap://ipdoservidor:porta'))) {
          die("Não foi possível se conectar com o servidor AD");
     } else {
          echo "Conectado com sucesso !!!";
     }
?>