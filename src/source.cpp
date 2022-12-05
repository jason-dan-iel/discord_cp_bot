#include <dpp/dpp.h>

const std::string BOT_TOKEN = "token";



// int main() {
//     dpp::cluster bot(BOT_TOKEN);
 
//     bot.on_log(dpp::utility::cout_logger());
 
//     bot.on_slashcommand([](const dpp::slashcommand_t& event) {
//          if (event.command.get_command_name() == "ping") {
//             event.reply("Pong!");
//         }
//     });
 
//     bot.on_ready([&bot](const dpp::ready_t& event) {
//         if (dpp::run_once<struct register_bot_commands>()) {
//             bot.global_command_create(
//                 dpp::slashcommand("ping", "Ping pong!", bot.me.id)
//             );
//         }
//     });
//     dpp::cluster bot(BOT_TOKEN, dpp::i_default_intents | dpp::i_message_content);
 
//     /* Message handler to look for a command called !embed */
//     bot.on_message_create([&bot](const dpp::message_create_t & event) {
//         if (event.msg.content == "!embed") {
 
//             /* create the embed */
//             dpp::embed embed = dpp::embed().
//                 set_color(dpp::colors::sti_blue).
//                 set_title("Github").
//                 set_url("https://github.com/jason-dan-iel/discord_cp_bot").
//                 set_author("Jason Daniel", "https://github.com/jason-dan-iel/discord_cp_bot", "embed/GitHub_Logo.png").
//                 set_description("This is the repo for bot").
//                 set_thumbnail("embed/GitHub_Logo.png").
//                 add_field(
//                         "Hey There!",
//                         "Checkout this cool repo"
//                 ).
//                 add_field(
//                         "Contributor 1",
//                         "Jason Daniel",
//                         true
//                 ).
//                 add_field(
//                         "Contributor 2",
//                         "Saksham Jain",
//                         true
//                 ).
//                 add_field(
//                         "Contributor ",
//                         "Anshul Thakur",
//                         true
//                 ).
//                 set_image("embed/GitHub_Logo.png").
//                 set_footer(dpp::embed_footer().set_text("Enjoy!").set_icon("embed/GitHub_Logo.png")).
//                 set_timestamp(time(0));
 
//             /* reply with the created embed */
//             bot.message_create(dpp::message(event.msg.channel_id, embed).set_reference(event.msg.id));
//         }
//     });

 
//     bot.start(dpp::st_wait);
// }

int main() {
    /* Setup the bot */
    dpp::cluster bot(BOT_TOKEN, dpp::i_default_intents | dpp::i_message_content);
 
    /* Message handler to look for a command called !embed */
    bot.on_message_create([&bot](const dpp::message_create_t & event) {
        if (event.msg.content == "!embed") {
 
            /* create the embed */
            dpp::embed embed = dpp::embed().
                set_color(dpp::colors::sti_blue).
                set_title("Some name").
                set_url("https://dpp.dev/").
                set_author("Some name", "https://dpp.dev/", "https://dpp.dev/DPP-Logo.png").
                set_description("Some description here").
                set_thumbnail("https://dpp.dev/DPP-Logo.png").
                add_field(
                        "Regular field title",
                        "Some value here"
                ).
                add_field(
                        "Inline field title",
                        "Some value here",
                        true
                ).
                add_field(
                        "Inline field title",
                        "Some value here",
                        true
                ).
                set_image("https://dpp.dev/DPP-Logo.png").
                set_footer(dpp::embed_footer().set_text("Some footer text here").set_icon("https://dpp.dev/DPP-Logo.png")).
                set_timestamp(time(0));
 
            /* reply with the created embed */
            bot.message_create(dpp::message(event.msg.channel_id, embed).set_reference(event.msg.id));
        }
    });
 
    bot.start(dpp::st_wait);
    return 0;
}
    