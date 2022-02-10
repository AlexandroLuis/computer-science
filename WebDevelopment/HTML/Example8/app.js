function limpaEndereco() {
    document.getElementById("rua").value = ("");
    document.getElementById("bairro").value = ("");
    document.getElementById("cidade").value = ("");
    document.getElementById("estado").value = ("");
}

function preencheEndereco(conteudo) {
    if (!("erro" in conteudo)) {
        document.getElementById("rua").value = (conteudo.logradouro);
        document.getElementById("bairro").value = (conteudo.bairro);
        document.getElementById("cidade").value = (conteudo.localidade);
        document.getElementById("estado").value = (conteudo.uf);
        document.getElementById("rua").disabled = true
        document.getElementById("bairro").disabled = true
        document.getElementById("cidade").disabled = true
        document.getElementById("estado").disabled = true

    } else {
        alert("Cep Não Encontrado!");
        limpaEndereco();
    }
}

function pesquisaCep(valor) {
    var cep = valor.replace(/\D/g, '');
    if (cep != "") {
        var validacep = /^[0-9]{8}$/;
        if (validacep.test(cep)) {
            document.getElementById("rua").value = ("...");
            document.getElementById("bairro").value = ("...");
            document.getElementById("cidade").value = ("...");
            document.getElementById("estado").value = ("...");

            var script = document.createElement('script');
            script.src = 'https://viacep.com.br/ws/' + cep + '/json/?callback=preencheEndereco';
            document.body.appendChild(script)
        }
    } else {
        limpaFormulario();
    }
}
function Enviar() {
    var nomeid = document.getElementById("nome").value;

    if (nomeid == "") {
        alert("O campo NOME é obrigatório!")
    } else {
        if (document.getElementById('rg').value == "") {
            alert("O campo RG é obrigatório!")
        } else {
            if (cpf = document.getElementById("cpf").value == "") {
                alert("O campo CPF é obrigatório!")
            } else {
                if (document.getElementById('nascimento').value == "") {
                    alert("O campo DATA DE NASCIMENTO é obrigatório!")
                } else {
                    if(document.getElementById('sexo') == "") {
                        alert("O campo SEXO é obrigatório")
                } else
                    if (!validarCPF(document.getElementById("cpf").value)) {
                        alert("CPF inválido!")
                    } else {
                        if (document.getElementById("cep").value == "") {
                            if (document.getElementById("rua").value == "") {
                                alert("O campo RUA é obrigatório!")
                            } else
                                if (document.getElementById("bairro").value == "") {
                                    alert("O campo BAIRRO é obrigatório!")
                                } else
                                    if (document.getElementById("cidade").value == "") {
                                        alert("O campo CIDADE é obrigatório!")
                                    } else
                                        if (document.getElementById("estado").value == "") {
                                            alert("O campo ESTADO é obrigatório!")
                                        }
                        } else {
                            alert(`Olá ${nomeid}, Agradecemos sua submissão!`);
                            window.location.replace("Agradecimento.html");
                        }
                    }
                }
            }
        }
    }



}
function preencheFormacao() {
    let formacao = ["Ensino Fundamental Incompleto", "Ensino Fundamental", "Ensino Médio Incompleto", "Ensino Médio", "Ensino Superior Incompleto", "Ensino Superior"]
    let formacaoSelect = document.getElementById('formacao')
    for (let i = 0; i < formacao.length; i++) {
        let option = document.createElement('option')
        option.value = formacao[i]
        option.text = formacao[i]
        formacaoSelect.appendChild(option)
    }
}
function validarCPF(cpf) {
    cpf = cpf.replace(/[^\d]+/g, '');
    if (cpf == '') return false;
    // Elimina CPFs invalidos conhecidos	
    if (cpf.length != 11 ||
        cpf == "00000000000" ||
        cpf == "11111111111" ||
        cpf == "22222222222" ||
        cpf == "33333333333" ||
        cpf == "44444444444" ||
        cpf == "55555555555" ||
        cpf == "66666666666" ||
        cpf == "77777777777" ||
        cpf == "88888888888" ||
        cpf == "99999999999")
        return false;
    // Valida 1o digito	
    add = 0;
    for (i = 0; i < 9; i++)
        add += parseInt(cpf.charAt(i)) * (10 - i);
    rev = 11 - (add % 11);
    if (rev == 10 || rev == 11)
        rev = 0;
    if (rev != parseInt(cpf.charAt(9)))
        return false;
    // Valida 2o digito	
    add = 0;
    for (i = 0; i < 10; i++)
        add += parseInt(cpf.charAt(i)) * (11 - i);
    rev = 11 - (add % 11);
    if (rev == 10 || rev == 11)
        rev = 0;
    if (rev != parseInt(cpf.charAt(10)))
        return false;
    return true;
}
jQuery(function ($) {
    $("#data").mask("99/99/9999");
    $("#telefone").mask("(99) 99999-9999");
    $("#cpf").mask("999.999.999-99");
    $("#cep").mask("99.999-999");
    $("#rg").mask("99.999.999-9");
})