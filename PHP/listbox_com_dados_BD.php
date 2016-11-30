<select name="responsavel" id="responsavel">
     <?php
          //acesso ao bd
          include "conecta_banco.inc";
          $sql = mysql_query("SELECT nome,id FROM usuarios") or die(mysql_error());
          while($row=mysql_fetch_array($sql)){
               echo "<option value=".$row['id'].">".$row['nome']."</option>";
          }
          mysql_close($con);
     ?>
</select>