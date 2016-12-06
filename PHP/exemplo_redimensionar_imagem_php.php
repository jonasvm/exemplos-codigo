<?php
     function redimensiona($origem,$destino,$maxlargura=100,$maxaltura=100,$qualidade=80)
     {
          if(!strstr($origem,"http") && !file_exists($origem)){
               echo("Arquivo de origem da imagem inexistente");
               return false;
          }
		  
          $ext = strtolower(end(explode('.', $origem)));
		  
          if($ext == "jpg"|| $ext == "jpeg"){
               $img_origem = @imagecreatefromjpeg($origem);
          }
          elseif ($ext == "gif"){
               $img_origem = @imagecreatefromgif($origem);
          }
          elseif ($ext == "png"){
               $img_origem = @imagecreatefrompng($origem);
          }
		  
          if(!$img_origem){
               echo("Erro ao carregar a imagem, talvez formato nao suportado");
               return false;
          }
		  
          $alt_origem = imagesy($img_origem);
          $lar_origem = imagesx($img_origem);
          $escala = min($maxaltura/$alt_origem, $maxlargura/$lar_origem);
          
		  if($escala < 1){
               $alt_destino = floor($escala*$alt_origem);
               $lar_destino = floor($escala*$lar_origem);
               // Cria imagem de destino
               $img_destino = imagecreatetruecolor($lar_destino,$alt_destino);
               // Redimensiona
               imagecopyresampled($img_destino, $img_origem, 0, 0, 0, 0, $lar_destino, $alt_destino, $lar_origem, $alt_origem);
               imagedestroy($img_origem);
          }
          else {
               $img_destino = $img_origem;
          }
		  
          $ext = strtolower(end(explode(".", $destino)));
		  
          if($ext == "jpg" || $ext == "jpeg"){
               imagejpeg($img_destino,$destino,$qualidade);
               return true;
          }
          elseif ($ext == "gif"){
               imagepng($img_destino,$destino);
               return true;
          }
          elseif ($ext == "png"){
               imagepng($img_destino,$destino);
               return true;
          }
          else {
               echo("Formato de destino nao suportado");
               return false;
          }
     }
	 
	 //Para usar
	 $origem = "imagem.jpg";
     $destino = "imagem1.jpg";
     redimensiona($origem,$destino,$maxlargura=100,$maxaltura=100,$qualidade=80)
?>