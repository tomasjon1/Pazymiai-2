#include "generation.h"

static std::random_device rd;
static std::mt19937 mt(rd());

const std::vector<std::string> firstNames = {"Abramas", "Abraomas", "Achilas", "Adalbertas", "Adamas", "Adas", "Adolfas", "Adolis", "Adomas",
                                             "Adrijus", "Agatas", "Agnius", "Aidas", "Ainius", "Aistis", "Aivaras", "Akimas", "Akvilinas", "Albertas", "Albrechtas",
                                             "Albinas", "Aldonas", "Aleksandras", "Aleksas", "Alenas", "Alfas", "Alfonsas", "Alfredas", "Algimantas", "Algirdas",
                                             "Algis", "Alius", "Almantas", "Almis", "Almonas", "Aloyzas", "Alpas", "Alpis", "Alvidas", "Alvydas", "Ambraziejus",
                                             "Anatolijus", "Anatolis", "Andreas", "Andriejus", "Andrius", "Andzejus", "Anicetas", "Anisimas", "Antanas", "Antonas",
                                             "Antonijus", "Antonis", "Anupras", "Anzelmas", "Apolinaras", "Apolonijus", "Aras", "Arijus", "Arimantas", "Aristarchas",
                                             "Aristidas", "Arkadijus", "Armantas", "Arminas", "Arnas", "Arnoldas", "Aronas", "Arsenas", "Arsenijus", "Artas",
                                             "Artiomas", "Arturas", "Arunas", "Arvaidas", "Arvydas", "Astijus", "Audrius", "Audrys", "Audronius", "Augis",
                                             "Augustas", "Augustinas", "Aurelijus", "Aurimas", "Ausrius", "Ausrys", "azuolas", "Balys", "Baltazaras", "Baltramiejus",
                                             "Baltrus", "Banguolis", "Bartas", "Bartvydas", "Bazilijus", "Benas", "Benediktas", "Benonas", "Benius", "Benjaminas",
                                             "Bernardas", "Berzas", "Bijunas", "Bogdanas", "Boguslavas", "Boleslavas", "Boleslovas", "Bonifacas", "Borisas",
                                             "Bronislavas", "Bronislovas", "Bronius", "Brunas", "Brunonas", "Cecilijus", "Celestinas", "Cezaris", "Chaimas",
                                             "Charitonas", "Ciprijonas", "cesius", "ceslovas", "ciogintas", "Dainius", "Daivis", "Dalius", "Damijonas", "Danas",
                                             "Dangerutis", "Danielius", "Danila", "Danius", "Darijus", "Darius", "Dariusas", "Daumantas", "Davidas", "Deimantas",
                                             "Deividas", "Deivis", "Demetrijus", "Demjanas", "Denis", "Denisas", "Dimitrijus", "Diomidas", "Dionizas", "Dmitrijus",
                                             "Dobilas", "Donatas", "Domantas", "Domas", "Dominykas", "Donaldas", "Dovydas", "Dovilis", "Dovis", "Drasius",
                                             "Drasutis", "Dzeraldas", "Dziraldas", "Dziugas", "Dzonis", "Edgaras", "Edmundas", "Eduardas", "Edvardas", "Edvinas",
                                             "Egidijus", "Eidimantas", "Eidminas", "Eidvydas", "Eimantas", "Eimis", "Einius", "Eivydas", "Eldaras", "Eligijus",
                                             "Elijus", "Elmantas", "Emanuelis", "Emilis", "Emilijonas", "Emilijus", "Enrikas", "Erazmas", "Erdvilas", "Erichas",
                                             "Erikas", "Ernestas", "Ervinas", "Eugenijus", "Eugeniusas", "Evaldas", "Fabijus", "Faustas", "Fedoras", "Felicijonas",
                                             "Felicijus", "Feliksas", "Ferdinandas", "Filipas", "Fiodoras", "Foma", "Flavijus", "Florijonas", "Francas",
                                             "Francisekas", "Fredas", "Fridrikas", "Gabrielis", "Gabrielius", "Gailimantas", "Gailius", "Galmantas", "Gasparas",
                                             "Gaudenis", "Gaudrimas", "Gaudvydas", "Gavrila", "Gavrilas", "Gedas", "Gedgaudas", "Gediminas", "Gedmantas", "Gedmas",
                                             "Gedminas", "Gedvaldas", "Gedvydas", "Gedvilas", "Geivydas", "Genadijus", "Gendrius", "Genrichas", "Georgijus",
                                             "Geraldas", "Gerardas", "Gerdas", "Gerimantas", "Germanas", "Germantas", "Gerutis", "Gervydas", "Giedrius", "Gilbertas",
                                             "Gintaras", "Gintas", "Gintis", "Gintautas", "Girenas", "Girius", "Girmantas", "Girvydas", "Gitanas", "Gytautas",
                                             "Gytis", "Gordejus", "Gotfridas", "Gracijonas", "Gracijus", "Grazvydas", "Grigalius", "Grigas", "Grigorijus", "Gunaras",
                                             "Gustas", "Gustavas", "Gustis", "Gvidas", "Gvidonas", "Haraldas", "Haris", "Haroldas", "Hektoras", "Helmutas",
                                             "Henrikas", "Henris", "Herbertas", "Herkus", "Hermanas", "Hilarijus", "Horacijus", "Horstas", "Hubertas", "Ignacas",
                                             "Ignas", "Ignotas", "Igoris", "Ilja", "Imantas", "Indrius", "Ingvaras", "Inocentas", "Ipolitas", "Irenijus", "Irmantas",
                                             "Irtautas", "Irvydas", "Isaakas", "Isakas", "Ivanas", "Izidorius", "Izoldas", "Jacekas", "Jakovas", "Jakubas", "Janas",
                                             "Janis", "Jankelis", "Janusas", "Jaroslavas", "Jaunius", "Jaunutis", "Jegoras", "Jemeljanas", "Jeronimas", "Jevgenijus",
                                             "Jezis", "Joanas", "Jogaila", "Jogintas", "Jogirdas", "Jokimas", "Jokubas", "Jolantas", "Jomantas", "Jonaras", "Jonas",
                                             "Jonis", "Joris", "Jorunas", "Josifas", "Jotautas", "Jovaldas", "Jovaras", "Jovitas", "Judrius", "Julijonas", "Julijus",
                                             "Julius", "Juljanas", "Juozapas", "Juozapatas", "Juozas", "Juras", "Jurgis", "Jurijus", "Juras", "Juris", "Justas",
                                             "Justinas", "Juvencijus", "Juzefas", "Kajetonas", "Kajus", "Kalikstas", "Kalnius", "Kamilis", "Kaributas", "Karlas",
                                             "Karolis", "Karpas", "Kasparas", "Kastantas", "Kastytis", "Kazimieras", "Kazys", "Kestas", "Kestautas", "Kestutis",
                                             "Kimas", "Kipras", "Kiprijonas", "Kirilas", "Klaudas", "Klaudijus", "Klemas", "Klemensas", "Klementas", "Kleopas",
                                             "Klevas", "Klimas", "Klimentijus", "Kondratas", "Konradas", "Konstantinas", "Kornelijus", "Kostas", "Kovas", "Kozmas",
                                             "Krescencijus", "Kristijonas", "Kristinas", "Kristoforas", "Kristupas", "Ksaveras", "Ksistofas", "Kuprijanas", "Laimis",
                                             "Laimonas", "Laimutis", "Laisvydas", "Laisvis", "Laisvunas", "Lauras", "Laurentijus", "Laurynas", "Lauris",
                                             "Lavrentijus", "Leandras", "Leonardas", "Leonas", "Leonidas", "Leopoldas", "Levas", "Libertas", "Linas", "Lionginas",
                                             "Liubartas", "Liubomiras", "Liucijonas", "Liucijus", "Liudas", "Liudvigas", "Liudvikas", "Liutas", "Liutauras",
                                             "Livijus", "Lozorius", "Lukas", "Lukrecijus", "Makaras", "Makarijus", "Maksas", "Maksimas", "Maksimilijonas",
                                             "Mamertas", "Manfredas", "Mangirdas", "Mantas", "Mantautas", "Mantrimas", "Mantvydas", "Maratas", "Marcelijus ",
                                             "Marcelinas", "Marcelius", "Marekas", "Margiris", "Marianas", "Marijonas", "Marijus", "Marinas", "Marius", "Markas",
                                             "Martas", "Martinas", "Martynas", "Matas", "Mateusas", "Matvejus", "Mazvydas", "Mecislavas", "Mecislovas", "Mecys",
                                             "Medardas", "Medas", "Mefodijus", "Melanijus", "Melchioras", "Mendelis", "Merkys", "Merunas", "Michalas", "Michailas",
                                             "Miglius", "Mikalojus", "Mikas", "Mikolajus", "Milanas", "Mildas", "Milvydas", "Mindaugas", "Minijus", "Mykolas",
                                             "Mingaudas", "Mintaras", "Miroslavas", "Modestas", "Morkus", "Motiejus", "Moze", "Naglis", "Napalis", "Napalys",
                                             "Napoleonas", "Napolis", "Narcizas", "Narimantas", "Narsutis", "Narvydas", "Natanas", "Natas", "Naumas", "Nauris",
                                             "Nazaras", "Nazarijus", "Nedas", "Neimantas", "Neivydas", "Nemunas", "Nerijus", "Nerimantas", "Nerimas", "Neringas",
                                             "Nerius", "Nidas", "Nikandras", "Nikas", "Nikiforas", "Nikita", "Nikodemas", "Nikola", "Nikolajus", "Nilas", "Nojus",
                                             "Nomedas", "Norbertas", "Normanas", "Normantas", "Nortautas", "Norvydas", "Norvilas", "Oktavijus", "Olegas", "Orestas",
                                             "Orintas", "Oskaras", "Osmundas", "Osvaldas", "Otas", "Otilijus", "Otonas", "Ovidijus", "Palemonas", "Palmyras",
                                             "Patricijus", "Patrikas", "Paulis", "Paulius", "Petras", "Pijus", "Pilypas", "Pilenas", "Piotras", "Platonas",
                                             "Polikarpas", "Polis", "Povilas", "Pranas", "Pranciskus", "Putinas", "Radvila", "Rafaelis", "Rafailas", "Rafalas",
                                             "Raigardas", "Raimondas", "Raimundas", "Rainoldas", "Ralfas", "Ramintas", "Ramonas", "Ramunas", "Rapolas", "Rasius",
                                             "Raulis", "Redas", "Regimantas", "Reginaldas", "Reinhardas", "Remas", "Remigijus", "Renaldas", "Renatas", "Renius",
                                             "Richardas", "Ricardas", "Rikardas", "Rimantas", "Rimas", "Rimgaudas", "Rimtas", "Rimtautas", "Rimtis", "Rimvydas",
                                             "Rinatas", "Rysardas", "Rytas", "Rytautas", "Rytis", "Robertas", "Robinas", "Rodrigas", "Rokas", "Rolandas", "Rolfas",
                                             "Romanas", "Romas", "Romualdas", "Ronaldas", "Rostislavas", "Rubenas", "Rudolfas", "Rufas", "Rufinas", "Rupertas",
                                             "Ruslanas", "Rutenis", "Sabinas", "Sakalas", "Saliamonas", "Salvijus", "Samuelis", "Samsonas", "Samuilas", "Sandras",
                                             "Santaras", "Saulenis", "Saulius", "Sava", "Sebastijonas", "Semas", "Semionas", "Serafinas", "Serapinas", "Sergejus",
                                             "Sergijus", "Serzas", "Severas", "Severinas", "Sidas", "Sidoras", "Sigis", "Sigitas", "Sigizmundas", "Sikstas",
                                             "Silverijus", "Silvestras", "Silvijus", "Simas", "Simeonas", "Simonas", "Sirvydas", "Skaidrius", "Skaistis",
                                             "Skalmantas", "Skalvis", "Skirgaila", "Skirmantas", "Skomantas", "Sonetas", "Stanislavas", "Stanislovas", "Stasys",
                                             "Stasius", "Stepas", "Stefanas", "Stepanas", "Steponas", "Svajunas", "Svajus", "Sviatoslavas", "sarunas", "siaurys",
                                             "svitrigaila", "Tadas", "Tadeusas", "Tamosius", "Tarasas", "Tauras", "Tautginas", "Tautrimas", "Tautvydas", "Tedas",
                                             "Telesforas", "Teisius", "Teisutis", "Teodoras", "Teofilis", "Terentijus", "Tiberijus", "Timas", "Timotiejus",
                                             "Timotis", "Timuras", "Titas", "Tomas", "Tomasas", "Tonis", "Traidenis", "Trofimas", "Tumas", "Ugnius", "Ulrikas",
                                             "Uosis", "Urbonas", "Utenis", "Ubaldas", "udrys", "ukas", "Vacys", "Vacius", "Vaclovas", "Vadimas", "Vaidas",
                                             "Vaidevutis", "Vaidila", "Vaidis", "Vaidotas", "Vaidutis", "Vaigaudas", "Vaigirdas", "Vainius", "Vainoras", "Vaitiekus",
                                             "Vaizgantas", "Vakaris", "Valdas", "Valdemaras", "Valdimantas", "Valdis", "Valentas", "Valentinas", "Valerijonas",
                                             "Valerijus", "Valys", "Valius", "Valteris", "Vasaris", "Vasilijus", "Venantas", "Verneris", "Vejas", "Vejunas",
                                             "Venjaminas", "Vergilijus", "Vestas", "Viaceslavas", "Vidas", "Vydas", "Vidimantas", "Vydimantas", "Vidmantas",
                                             "Vydmantas", "Viesulas", "Vygaudas", "Vigilijus", "Vygintas", "Vygirdas", "Vykantas", "Vykintas", "Viktas", "Viktoras",
                                             "Viktorijus", "Viktorinas", "Vilenas", "Vilgaudas", "Vilhelmas", "Vilijus", "Vilius", "Vylius", "Vilmantas", "Vilmas",
                                             "Vilnius", "Viltaras", "Viltautas", "Viltenis", "Vincas", "Vincentas", "Vingaudas", "Virgaudas", "Virgilijus",
                                             "Virginijus", "Virgintas", "Virgis", "Virgius", "Virmantas", "Vismantas", "Visvaldas", "Visvaldis", "Vitalijus",
                                             "Vitalis", "Vitalius", "Vitas", "Vitoldas", "Vygandas", "Vygantas", "Vykintas", "Vytaras", "Vytautas", "Vytas",
                                             "Vytenis", "Vytis", "Vyturys", "Vladas", "Vladimiras", "Vladislavas", "Vladislovas", "Vladlenas", "Voicechas",
                                             "Voldemaras", "Vsevolodas", "Zacharijus", "Zakarijus", "Zbignevas", "Zdislavas", "Zenius", "Zenonas", "Zigfridas",
                                             "Zygfridas", "Zigmantas", "Zigmas", "Zygmuntas", "Zinovijus", "zanas", "zeimantas", "zilvinas", "zibartas", "zybartas",
                                             "zydrius", "zydrunas", "zygaudas", "zygimantas", "zygintas", "zygis", "zymantas", "zvaigzdzius"};

const std::vector<std::string> lastNames = {"Kazlaukas", "Jankauskas", "Petrauskas", "Stankevicius", "Vasiliauskas", "zukauskas", "Butkus",
                                            "Kateiva", "Paulauskas", "Urbonas", "Kavaliauskas", "Baranauskas", "Pocius", "Sakalauskas"};

Generator::Generator()
{
}

Generator::~Generator()
{
}

int Generator::randomInt(int from, int to)
{
    std::uniform_int_distribution<int> dist(from, to);
    return dist(mt);
}

string Generator::randFirstName()
{
    return firstNames[randomInt(0, firstNames.size() - 1)];
}

string Generator::randLastName()
{
    return lastNames[randomInt(0, lastNames.size() - 1)];
}

void Generator::genFile(int size, string file_name, int ndCount)
{
    std::stringstream outputas;
    outputas << std::left << std::setw(20) << "Vardas";
    outputas << std::left << std::setw(20) << "Pavarde";
    for (int i = 1; i <= ndCount; i++)
    {
        outputas << std::left << "ND" << std::setw(5) << i;
    }

    outputas << std::left << std::setw(7) << "Egz" << endl;

    for (int i = 0; i < size; i++)
    {
        outputas << genStudentString(ndCount).str();
    }
    std::ofstream out_f(file_name);
    out_f << outputas.rdbuf();
    out_f.close();
}

std::stringstream Generator::genStudentString(int ndCount)
{
    std::stringstream stud;

    stud << std::left << std::setw(20) << randFirstName();
    stud << std::left << std::setw(20) << randLastName();
    for (int i = 0; i < ndCount; i++)
        stud << std::left << std::setw(7) << randomInt(1, 10);
    stud << std::left << std::setw(7) << randomInt(1, 10) << endl;
    return stud;
}