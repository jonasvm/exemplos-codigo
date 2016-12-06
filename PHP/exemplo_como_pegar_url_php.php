<?php
     $url1 = "http://" . $_SERVER['SERVER_NAME'].$_SERVER['REQUEST_URI'];
     echo $url1;
     echo "<br><br>";
     
     $url2 = $_SERVER['HTTP_HOST'];
     echo $url2;
     echo "<br><br>";
     
     $url3 = $_SERVER['PHP_SELF'];
     echo $url3;
     echo "<br><br>";
?>