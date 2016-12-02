<?php
     
	 //início da conexão
     $db = 'localhost:C:\Documents and Settings\usuario\pasta_do_bd\Nome_do_banco.FDB';
     $user = 'SYSDBA'; /* este é o usuário padrão do Firebird */
     $password = 'masterkey'; /* esta senha também é padrão */
     $res = ibase_connect($db,$user,$password) or die("<br>" . ibase_errmsg());
     
	 // Query
     $sql = "SELECT * FROM Tabela";
     
     $result = ibase_query($res,$sql) or die(ibase_errmsg()); /* enviando a query ao banco  */
     
	 while($row=ibase_fetch_object($result)){
          // use $row->FIELDNAME not $row->fieldname
          echo $row->FIELDNAME;
     }
     
     ibase_free_result($result);
     
	 // Closing
     ibase_close($res) or die("<br>" . ibase_errmsg());

?>