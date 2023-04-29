# Controlador_esteira
O algoritmo para essa controladora está separado em tasks que estão localizadas na pasta [lib](./lib) que possuem cada uma a sua função e executam paralelamente no microcontrolador, sendo as tasks utilizadas pela controladora as listadas abaixo:


- ## [TaskIHM](./lib/TaskIHM/src)

Essa task tem como função exibir alguns dados no display LCD e enviar para a esteira qual deverá ser a velocidade e sentido de rotação do motor dela. Com isso, o controle do motor da esteira
é feito com um potenciômetro que é lido nessa task e os dados provenientes dele são tratados e encapsulados em um pacote que é enviado para a TaskEspNow.

Além disso, os dados exibidos no display LCD são controlados por um botão, sendo que quando o botão é pressionado o display passa a exibir outros tipos de dados, portanto o display LCD exibirá
na tela o duty cycle do pwm do motor e o sentido de rotação dele ou o estado do sensor IR e a quantidade de peças rejeitadas.
- ## [TaskEspNow](./lib/TaskEspNow/src)

Essa task tem como função tratar da comunicação sem fio da esteira com a controladora dela, via protocolo Esp-Now.

Além disso, os dados compartilhados entre as tasks e também utilizados como pacotes para o protocolo Esp-Now, estão na estrutura definida no arquivo [SharedStruct](./lib/SharedStruct/src)

Para mais informações sobre a esteira, acesse o repositório a seguir: [Projeto_esteira](https://github.com/Matheus-de-Sousa/Projeto_Esteira) 
