# StarEntregas
Implementação do problema do carteiro chinês num cenário de Star Wars, alguns planetas, vértices, não podem ser acessados em tempos específicos.

### Cenário
Somos uma empresa de entrega de clones que tem de entregar, passar, por vários planetas e voltar para o planeta base no menor tempo possível para maximizar o nosso lucro. Sabemos que em horas específicas alguns planetas negam qualquer acesso ao seu sistema, tendo, essa possibilidade, de ser inserida em nosso cálculo de entrega.

### Como
Resolvemos o problema usando o algoritimo de diijkstra, com um grafo de lista de adjacências. Para decidir o caminho testamos todas as possilidades, excluindo manualmente casos claramente inviáveis para melhorar a perfomance/tempo, e escolhemos o sequência de vértice que têm, no total, o menor tempo.




