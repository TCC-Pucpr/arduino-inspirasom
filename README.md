# Protótipo - Arduino

Neste repositório, está contido o código do software.

Esta é uma branch separada da develop, então o histórico de modificações pode ser claramente vistas
para que consiga confirmar que não houve mudanças após a data de entrega.

### Como rodar o programa

Pode usar qualquer sistema operacional, porém para que
você consiga compilar e executar o programa, você vai precisar ter instalado no seu computador:

- [Arduino IDE](https://www.arduino.cc/en/software)
- [Control-Surface](https://github.com/tttapa/Control-Surface), baixar o zip do repositório e instalar pela IDE

Além disso, voce vai precisar também ter um arduino em mão, que tenha capacidade de produzir saída MIDI, ou
fazer flash da firmware [USBMidiKlik](https://github.com/TheKikGen/USBMidiKliK) seguindo o guia disponivel 
[neste link](https://github.com/TheKikGen/USBMidiKliK/wiki#flashing-the-atmega16u2).

Se você fizer flash deste firmware, para fazer upload do código voce precisa ligar
as portas PB2/MOSI do arduino com o GND. Quando ligar o arduino ele ligará no modo serial,
permitindo upload do codigo.

### Código do Software

O projeto consiste em dois repositórios, este, e o do código do software para rodar no computaador,
que pode ser encontrado acessando [link](https://github.com/TCC-Pucpr/fed-inspirasom/tree/20-prototipo).

Este link irá redireciona-lo para uma branch parecida com essa, onde não
haverá mudanças a partir da data de entrega.