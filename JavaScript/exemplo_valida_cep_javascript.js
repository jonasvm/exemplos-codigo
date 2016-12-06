<!-- Trecho inserido entre as tags <head></head>-->
<script type="text/javascript">
    <!--
    // Função para retirar os espaços em branco do início e do fim da string.
    function Trim(strTexto)
        {
            // Substitúi os espaços vazios no inicio e no fim da string por vazio.
            return strTexto.replace(/^\s+|\s+$/g, '');
        }

    // Função para validação de CEP.
    function IsCEP(strCEP, blnVazio)
        {
            // Caso o CEP não esteja nesse formato ele é inválido!
            var objER = /^[0-9]{2}\.[0-9]{3}-[0-9]{3}$/;

            strCEP = Trim(strCEP)
            if(strCEP.length > 0)
                {
                    if(objER.test(strCEP))
                        return true;
                    else
                        return false;
                }
            else
                return blnVazio;
        }
    //-->
</script>

<!-- Essa função pode ser chamada na saída do campo CEP, no evento onBlur do textbox
     ou então no submit da página, no evento onSubmit do formulário.
 -->