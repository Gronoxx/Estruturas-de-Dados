#include <iostream>
#include "../include/pilha.hpp"
#include <math.h>
#include "../include/reta.hpp"
#include "../include/fechoconvexo.hpp"
#include <fstream>
#include <chrono>
#include <iomanip>

#include <SFML/Graphics.hpp>

fechoconvexo f;

int distSq(Ponto p1, Ponto p2)
{
    return (p1.x - p2.x)*(p1.x - p2.x) +
          (p1.y - p2.y)*(p1.y - p2.y);
}

int find_max_Y(Ponto pontos[],int n){
        int maior_y = pontos[0].y;
    for (int i = 1; i < n; i++) {
        if (pontos[i].y > maior_y) {
            maior_y = pontos[i].y;
        }
    }
    return maior_y;
}
double find_max_PA(Ponto pontos[],int n){
        double maior_pa = pontos[0].pa;
    for (int i = 1; i < n; i++) {
        if (pontos[i].pa > maior_pa) {
            maior_pa = pontos[i].pa;
        }
    }
    return maior_pa;
}

int ccw(Ponto p, Ponto q, Ponto r)
{
	int val = (q.y - p.y) * (r.x - q.x) -
			(q.x - p.x) * (r.y - q.y);

	if (val == 0) return 0; // collinear
	return (val > 0)? 1: 2; // clock or counterclock wise
}


double reta_gradiente(Reta r){
    if(r.p1.x-r.p2.x==0){
    throw "reta perpendicular";
    }
    double m = (r.p1.y - r.p2.y)/(1.0 * r.p1.x-r.p2.x);
    return m; 
}
double polar_angle(Reta r1, Reta r2){
    double m1= 0;
    double m2=0;
    try{
    m2= reta_gradiente(r2);
    }catch(char const * msg){
        return 90;
    }
    double tan = (m2-m1)/(1+(m2*m1)); // me*m1 sempre 0 então sem erro de divisão por 0
    double angulo_rad = atan(tan);
    double angulo_deg = angulo_rad *180/M_PI;
    if(angulo_deg<0)
    return angulo_deg+180;
    return angulo_deg;
}


void Insercao(Ponto * v, int n,int id){
int i,j;
Ponto aux;
if(id==1){  
for (i = 1; i < n; i++) {
aux = v[i];
j = i - 1;
while (( j >= 0 ) && (aux.y < v[j].y)) {
v[j + 1] = v[j];
j--;
}
v[j + 1] = aux;
}
}
else if(id==0){ 
for (i = 2; i < n; i++) {
aux = v[i];
j = i - 1;
while (( j >= 1 ) && (aux.pa < v[j].pa)) {
v[j + 1] = v[j];
j--;
}
v[j + 1] = aux;
}
}
else if(id==3){ //pa direta do bucket 
for (i = 1; i < n; i++) {
aux = v[i];
j = i - 1;
while (( j >= 0 ) && (aux.pa < v[j].pa)) {
v[j + 1] = v[j];
j--;
}
v[j + 1] = aux;
}
}
}

void BucketSort(Ponto arr[], int n, int max, int id){
    int num_buckets=0;
    const int tamanho_bucket=10;
    if(id==0){
        num_buckets=max/tamanho_bucket + 1;
        Ponto ** vetores=new Ponto*[num_buckets]();//cria um array de ponteiros para vetores
        int * size_index = new int[num_buckets]();//armazena a quantidade de elementos por bucket
        //Descobre quantos pontos tem em cada bucket, essa etapa é feita primeiro para saber o tamanho de cada vetor
        for (int i = 1; i < n; i++) {
        int index=arr[i].pa/10; //descobre o index do bucket
        size_index[index]++;//acrescenta em um a quantidade de elementos daquele bucket
        }
        // Cria o espaço de memória para cada bucket
        for (int i = 0; i < num_buckets; i++) {
            vetores[i] = new Ponto[size_index[i]];
        }
        //zera tudo
        for (int i = 0; i < num_buckets; i++) {
         size_index[i] = 0;
        }
        // Atribuir pontos aos respectivos buckets com o pa
        for (int i = 1; i < n; i++) {
        int index=arr[i].pa/10; //descobre o index do bucket
        vetores[index][size_index[index]] = arr[i]; //bucket[index do bucket][valor correspondente ao tamanho atual daquele bucket, ou seja, a posição adequada]
        size_index[index]++;//incrementa a quantidade de elementos naquele bucket
        }
        //Ordena individualmente cada bucket
        for (int i = 0; i < num_buckets; i++) {
        Insercao(vetores[i], size_index[i],3);
        }
         // Concatenar os buckets ordenados
        int index = 1;
        for (int i = 0; i < num_buckets; i++) {
        for (int j = 0; j < size_index[i]; j++) {
            arr[index] = vetores[i][j];
            index++;
        }
        }

        for(int i=0;i<num_buckets;i++){
            delete[] vetores[i];
        }
        delete[] vetores;
        delete[] size_index;
    }
    else if(id==1){
        num_buckets=max/tamanho_bucket + 1;
        Ponto ** vetores=new Ponto*[num_buckets]();//cria um array de ponteiros para vetores
        int * size_index = new int[num_buckets]();//armazena a quantidade de elementos por bucket
        
        //Descobre quantos pontos tem em cada bucket, essa etapa é feita primeiro para saber o tamanho de cada vetor
        for (int i = 0; i < n; i++) {
        int index=arr[i].y/10; //descobre o index do bucket
        size_index[index]++;//acrescenta em um a quantidade de elementos daquele bucket
        }
        // Cria o espaço de memória para cada bucket
        for (int i = 0; i < num_buckets; i++) {
            vetores[i] = new Ponto[size_index[i]];
        }
        //zera tudo
        for (int i = 0; i < num_buckets; i++) {
         size_index[i] = 0;
        }
        // Atribuir pontos aos respectivos buckets com base nas coordenadas y
        for (int i = 0; i < n; i++) {
        int index=arr[i].y/10; //descobre o index do bucket
        vetores[index][size_index[index]] = arr[i]; //bucket[index do bucket][valor correspondente ao tamanho atual daquele bucket, ou seja, a posição adequada]
        size_index[index]++;//incrementa a quantidade de elementos naquele bucket
        }
        //Ordena individualmente cada bucket
        for (int i = 0; i < num_buckets; i++) {
        Insercao(vetores[i], size_index[i],1);
        }
         // Concatenar os buckets ordenados
        int index = 0;
        for (int i = 0; i < num_buckets; i++) {
        for (int j = 0; j < size_index[i]; j++) {
            arr[index] = vetores[i][j];
            index++;
        }
        }

        for(int i=0;i<num_buckets;i++){
            delete[] vetores[i];
        }
        delete[] vetores;
        delete[] size_index;
    }
}

void merge(Ponto arr[], int l, int m, int r, int id)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;


    // Create temp arrays
    Ponto L[n1], R[n2];
    if(id==1){
    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++){
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++){
        R[j] = arr[m + 1 + j];
    }
    // Merge the temp arrays back into arr[l..r
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i].y <= R[j].y) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    // Copy the remaining elements of L[],
    // if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    // Copy the remaining elements of R[],
    // if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    }
    else if(id == 0){
         // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    // Merge the temp arrays back into arr[l..r
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i].pa <= R[j].pa) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    // Copy the remaining elements of L[],
    // if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    // Copy the remaining elements of R[],
    // if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    }
}
 
// l is for left index and r is right index of the
// sub-array of arr to be sorted
void mergeSort(Ponto arr[], int l, int r, int id)
{
    if (l < r) {
        int m = l + (r - l) / 2;
 
        // Sort first and second halves
        mergeSort(arr, l, m,id);
        mergeSort(arr, m + 1, r,id);
 
        merge(arr, l, m, r,id);
    }
}

void jarvismarch(Ponto points[], int n){ // There must be at least 3 points
    if (n < 3) return;
  
  
    int l = 0;
    for (int i = 1; i < n; i++){
        if (points[i].x < points[l].x)
            l = i;
    }

    int p = l, q;
    do
    {
        f.Inserir(points[p]);

        q = (p+1)%n;
        for (int i = 0; i < n; i++)
        {   
           if (ccw(points[p], points[i], points[q]) == 2)
               q = i;
        }
  
        p = q;
  
    } while (p != l); 
}
void grahamscanI(Ponto * pontos, int n){
    //Descobrir aquele com menor y
    Insercao(pontos,n,1);
    //ordenar por polar angle

    //Setar os polar angle

    //cria a primeira reta que é a horizontal ao ponto mais baixo do polígono
    Reta r1;
    r1.p1.x=pontos[0].x;
    r1.p1.y=pontos[0].y;
    r1.p2.x=pontos[0].x+1;
    r1.p2.y=r1.p1.y;
    //cria a segunda reta que liga o ponto mais baixo do polígono com o próximo ponto
    Reta r2;
    for(int i=1;i<n;i++){
        r2.p1=r1.p1;
        r2.p2.x=pontos[i].x;
        r2.p2.y=pontos[i].y;
        pontos[i].Set_PA(polar_angle(r1,r2));
    }
    Insercao(pontos,n,0);
    int m = 1;
for (int i=1; i<n; i++)
{

	while (i < n-1 && ccw(pontos[0], pontos[i],
									pontos[i+1]) == 0)
		i++;
    
	pontos[m] = pontos[i];
	m++; 
}   
    if (m < 3) return;
    //CRIAR A PILHA
    Pilha p;
    p.Empilha(pontos[0]);
    p.Empilha(pontos[1]);
    p.Empilha(pontos[2]);
    for(int count=3;count<m;count++){
        while(p.tamanho>1 && ccw((p.topo2->Get_Item()),p.Get_Item_Topo(),pontos[count])!=2){
            p.Desempilha();
        }
        p.Empilha(pontos[count]);
    }
   while (!p.Vazia())
   {
       Ponto po = p.Get_Item_Topo();
       f.Inserir(po);
       p.Desempilha();       
   }

}

void grahamscanM(Ponto * pontos, int n){
    //Descobrir aquele com menor y
    mergeSort(pontos,0,n-1,1);
    //ordenar por polar angle

    //Setar os polar angle

    //cria a primeira reta que é a horizontal ao ponto mais baixo do polígono
    Reta r1;
    r1.p1.x=pontos[0].x;
    r1.p1.y=pontos[0].y;
    r1.p2.x=pontos[0].x+1;
    r1.p2.y=r1.p1.y;
    //cria a segunda reta que liga o ponto mais baixo do polígono com o próximo ponto
    Reta r2;
    for(int i=1;i<n;i++){
        r2.p1=r1.p1;
        r2.p2.x=pontos[i].x;
        r2.p2.y=pontos[i].y;
        pontos[i].Set_PA(polar_angle(r1,r2));
    }
    mergeSort(pontos,1,n-1,0);
    int m = 1;
for (int i=1; i<n; i++)
{

	while (i < n-1 && ccw(pontos[0], pontos[i],
									pontos[i+1]) == 0)
		i++;
    
	pontos[m] = pontos[i];
	m++; 
}   
    if (m < 3) return;
    //CRIAR A PILHA
    Pilha p;
    p.Empilha(pontos[0]);
    p.Empilha(pontos[1]);
    p.Empilha(pontos[2]);
    for(int count=3;count<m;count++){
        while(p.tamanho>1 && ccw((p.topo2->Get_Item()),p.Get_Item_Topo(),pontos[count])!=2){
            p.Desempilha();
        }
        p.Empilha(pontos[count]);
    }
   while (!p.Vazia())
   {
       Ponto po = p.Get_Item_Topo();
       f.Inserir(po);
       p.Desempilha();       
   }

}

void grahamscanB(Ponto * pontos, int n){
    //Descobrir aquele com menor y
    BucketSort(pontos,n,find_max_Y(pontos,n),1);
    //ordenar por polar angle

    //Setar os polar angle

    //cria a primeira reta que é a horizontal ao ponto mais baixo do polígono
    Reta r1;
    r1.p1.x=pontos[0].x;
    r1.p1.y=pontos[0].y;
    r1.p2.x=pontos[0].x+1;
    r1.p2.y=r1.p1.y;
    //cria a segunda reta que liga o ponto mais baixo do polígono com o próximo ponto
    Reta r2;
    for(int i=1;i<n;i++){
        r2.p1=r1.p1;
        r2.p2.x=pontos[i].x;
        r2.p2.y=pontos[i].y;
        pontos[i].Set_PA(polar_angle(r1,r2));
    }
    BucketSort(pontos,n,find_max_PA(pontos,n),0);
    int m = 1;
for (int i=1; i<n; i++)
{

	while (i < n-1 && ccw(pontos[0], pontos[i],
									pontos[i+1]) == 0)
		i++;
    
	pontos[m] = pontos[i];
	m++; 
}   
    if (m < 3) return;
    //CRIAR A PILHA
    Pilha p;
    p.Empilha(pontos[0]);
    p.Empilha(pontos[1]);
    p.Empilha(pontos[2]);
    for(int count=3;count<m;count++){
        while(p.tamanho>1 && ccw((p.topo2->Get_Item()),p.Get_Item_Topo(),pontos[count])!=2){
            p.Desempilha();
        }
        p.Empilha(pontos[count]);
    }
   while (!p.Vazia())
   {
       Ponto po = p.Get_Item_Topo();
       f.Inserir(po);
       p.Desempilha();       
   }

}

int main() {

    int videoCount;
    Ponto videoValues[10000];

    std::cout<<"Comandos:"<<std::endl;
    std::cout<<"Para receber o fecho e o tempo de execução: fecho <arquivo_entrada>"<<std::endl;
    std::cout<<"Para encerrar: exit"<<std::endl;
    std::string comando;
    while(std::cin>>comando){
    if(comando=="exit"){
        break;
    }
    else if(comando=="fecho"){
    std::string nome_arquivo;
    std::cin>>nome_arquivo;    
    const int MAX_SIZE = 10000; // Tamanho máximo do vetor
    Ponto values[MAX_SIZE],values1[MAX_SIZE],values2[MAX_SIZE],values3[MAX_SIZE];
    int count = 0;
    std::ifstream inputFile(nome_arquivo);
    if (!inputFile) {
        std::cerr << "Erro ao abrir o arquivo." << std::endl;
        return 1;
    }

    int x, y;
    while (inputFile >> x >> y) {
        if (count >= MAX_SIZE) {
            std::cerr << "Tamanho máximo do vetor atingido." << std::endl;
            break;
        }
        values[count].x = x;
        values[count].y = y;
        values1[count].x = x;
        values1[count].y = y;
        values2[count].x = x;
        values2[count].y = y;
        values3[count].x = x;
        values3[count].y = y;
        count++;
    }

    inputFile.close();

    int size = count;
    //Inicio relogio Merge
    auto inicio = std::chrono::high_resolution_clock::now();
    grahamscanM(values,count);
    //Fim relógio Merge
    auto fim = std::chrono::high_resolution_clock::now();
    //Calculando tempo total
    std::chrono::duration<double,std::micro> tempo = fim - inicio;
    double tempoSegundosMergeSort = tempo.count();
    //limpando o fecho
    f.Limpa();
    //Insertion
    inicio = std::chrono::high_resolution_clock::now();

    grahamscanI(values1,count);

    fim = std::chrono::high_resolution_clock::now();
    
    tempo = fim - inicio;
    double tempoSegundosInsertionSort = tempo.count();
    //limpando o fecho
    f.Limpa();
    //Jarvis
    inicio = std::chrono::high_resolution_clock::now();

    jarvismarch(values2,count);

    fim = std::chrono::high_resolution_clock::now();
    
    tempo = fim - inicio;
    double tempoSegundosJarvisMarch = tempo.count();

    videoCount = count;
    for(int i = 0; i < 10000; i++){
        videoValues[i] = values2[i];
    }

    //limpando o fecho
    f.Limpa();
    //Bucket
    inicio = std::chrono::high_resolution_clock::now();

    grahamscanB(values3,count);

    fim = std::chrono::high_resolution_clock::now();
    
    tempo = fim - inicio;
    double tempoSegundosBucketSort = tempo.count();

    std::cout<<"FECHO CONVEXO:"<<std::endl;
    f.Imprimir();
    f.Limpa();
    std::cout<<std::endl;
    std::cout << std::fixed << std::setprecision(3);
    std::cout<<"GRAHAM+MERGESORT: "<<tempoSegundosMergeSort<<"microsegundos"<<std::endl;
    std::cout<<"GRAHAM+INSERTIONSORT: "<<tempoSegundosInsertionSort<<"microsegundos"<<std::endl;
    std::cout<<"GRAHAM+LINEAR: "<<tempoSegundosBucketSort<<"microsegundos"<<std::endl;
    std::cout<<"JARVIS: "<<tempoSegundosJarvisMarch<<"microsegundos"<<std::endl;


    //INICIO DA PARTE GRÁFICA
    std::cout<<"\n\t Iniciando demonstração gráfica\n";
    std::cout<<"\n\t Para terminá-la, feche a janela gerada pelo X dela\n";
    std::cout<<"\n\t Espere que o programa confirme que a janela foi fechada com sucesso até inserir outro comando\n";

    jarvismarch(videoValues, videoCount);

    //Criar Janela
        sf::RenderWindow window(sf::VideoMode(800, 600), "Fecho Convexo");

        //Calcular posição para centralizar a janela
        sf::Vector2i screenCenter(sf::VideoMode::getDesktopMode().width / 2, sf::VideoMode::getDesktopMode().height / 2);
        sf::Vector2i windowPosition(screenCenter - sf::Vector2i(window.getSize().x / 2, window.getSize().y / 2));

        //Setar a posição da janela
        window.setPosition(windowPosition);
        
        while (window.isOpen()) {
            //Processar eventos
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed){
                    window.close();
                }
            }

            //Limpar a Janela
            window.clear();

            //Calcular centro da janela
            sf::Vector2f windowCenter(800 / 2.f, 600 / 2.f);

            //Calcular distância máxima permitida do centro
            float maxDistance = 0.f;
            for (int i = 0; i < f.size; ++i) {
                float distance = std::max(std::abs(f.pontos_fecho[i].x), std::abs(f.pontos_fecho[i].y));
                maxDistance = std::max(maxDistance, distance);
            }

            //Fator de escala para as coordenadas
            float scaleFactor = std::min(400.f / maxDistance, 300.f / maxDistance);

            //Calcular centro do Polígono
            sf::Vector2f centroid(0.0f, 0.0f);
            for (int i = 0; i < f.size; ++i) {
                centroid.x += f.pontos_fecho[i].x;
                centroid.y += f.pontos_fecho[i].y;
            }
            centroid /= static_cast<float>(f.size);

            //Desenhar todos os pontos em Azul
            for (int i = 0; i < videoCount; ++i) {
                sf::Vector2f translatedPoint = windowCenter + sf::Vector2f((videoValues[i].x - centroid.x) * scaleFactor, (videoValues[i].y - centroid.y) * scaleFactor);

                //Desenhar vertex
                sf::CircleShape vertex(2.5f);
                vertex.setFillColor(sf::Color::Green);
                vertex.setOrigin(1.5f, 1.5f);
                vertex.setPosition(translatedPoint);
                window.draw(vertex);
            }

            //Desenhar vértices em Verde
            for (int i = 0; i < f.size; ++i) {
                sf::Vector2f translatedPoint = windowCenter + sf::Vector2f((f.pontos_fecho[i].x - centroid.x) * scaleFactor, (f.pontos_fecho[i].y - centroid.y) * scaleFactor);

                //Desenhar vertex
                sf::CircleShape vertex(3.0f);
                vertex.setFillColor(sf::Color::Blue);
                vertex.setOrigin(1.5f, 1.5f);
                vertex.setPosition(translatedPoint);
                window.draw(vertex);
            }

            //Desenhar Linhas em Vermelho
            for (int i = 0; i < f.size; ++i) {
                sf::Vector2f translatedPoint = windowCenter + sf::Vector2f((f.pontos_fecho[i].x - centroid.x) * scaleFactor, (f.pontos_fecho[i].y - centroid.y) * scaleFactor);
                sf::Vector2f nextTranslatedPoint = windowCenter + sf::Vector2f((f.pontos_fecho[(i + 1) % f.size].x - centroid.x) * scaleFactor, (f.pontos_fecho[(i + 1) % f.size].y - centroid.y) * scaleFactor);

                //Desenhar linha
                sf::Vertex line[] = {
                    sf::Vertex(translatedPoint),
                    sf::Vertex(nextTranslatedPoint)
                };
                line[0].color = sf::Color::Yellow;
                line[1].color = sf::Color::Yellow;
                window.draw(line, 2, sf::Lines);

                window.display();
                sf::sleep(sf::seconds(0.5f));
            }

            //Mostrar Janela
            window.display();
        }
        f.Limpa();
        std::cout << "\nJanela de visualização fechada com sucesso\n\n";

    }
    else{
    std::cout<<"COMANDO INVÁLIDO"<<std::endl;
    std::cout<<"Comandos:"<<std::endl;
    std::cout<<"Para receber o fecho e o tempo de execução: fecho <arquivo_entrada>"<<std::endl;
    std::cout<<"Para encerrar: exit"<<std::endl;   
    }
    }

    return 0;
}


