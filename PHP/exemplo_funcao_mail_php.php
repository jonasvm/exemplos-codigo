<?php

     $email = "endereço do destinatário" ;
     $assunto = "assunto do email";
     $mensagem = "Texto do email" ;
     $remetente = "endereço do remetente";
     
     if(mail( $remetente, $assunto, $mensagem, "From: $email" ))
          echo "Email enviado.";
     else
          echo "Erro";

?>