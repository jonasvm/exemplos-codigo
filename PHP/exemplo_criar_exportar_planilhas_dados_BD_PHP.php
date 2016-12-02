<?php
     //-- conecta no banco de dados automaticamente, tem um post aqui
     //-- no blog ensinando como fazer
     include "conecta_mysql.inc";
	 
     //- Definimos o nome do arquivo que será exportado -------------
     $arquivo = 'planilha.xls';

	 //--- Consultando dados no banco -------------------------------
	 $sql = mysql_query("SELECT campo1,campo2,campo3 FROM tabela") or die(mysql_error());

	 //--- Fazendo o preenchimento inicial --------------------------
	 $row=mysql_fetch_array($sql);
	 
     //--- Contando o numero de linhas que a consulta gerou ---------
     $sql2 = mysql_query("SELECT * FROM formulario");
     $aux = mysql_num_rows($sql2);

	 // Criamos uma tabela HTML com o formato da planilha
     $html = '';
     $html .= '<table border="1">';
     $html .= '<tr>';
     $html .= '<td colspan="3"><b>Gerando uma planilha</b></td></tr>';
	 
     // -- Cabeçalho do arquivo -------------------------------------
     $html .= '<tr><td align="center"><b>Campo 1</b></td>';
     $html .= '<td align="center"><b>Campo 2</b></td>';
     $html .= '<td align="center"><b>Campo 3</b></td></tr>';

	 //--------------------------------------------------------------
     for($i=1; $i<=$aux; $i ++){
          $sql = mysql_query("SELECT campo1,campo2,campo3 FROM tabela WHERE id = ".$i) or die(mysql_error());
          $row=mysql_fetch_array($sql);
          $html .= '<tr><td>'.$row[0].'</td><td>'.$row[1].'</td>
          <td>'.$row[2].'</td></tr>';
     }
     $html .= '</table>';

	 // Configurações header para forçar o download
     header ("Expires: Mon, 26 Jul 1997 05:00:00 GMT");
     header ("Last-Modified: " . gmdate("D,d M YH:i:s") . " GMT");
     header ("Cache-Control: no-cache, must-revalidate");
     header ("Pragma: no-cache");
     header ("Content-type: application/x-msexcel");
     header ("Content-Disposition: attachment; filename=\"{$arquivo}\"" );
     header ("Content-Description: PHP Generated Data" );

	 // Envia o conteúdo do arquivo
     echo $html;

	 exit;
?>