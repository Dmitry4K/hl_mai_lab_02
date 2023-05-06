-- Для тестирования подойдут пользователи с 1, 2, 3

insert into User(first_name, last_name, login, password, email, title) values ('name1', 'name1', 'name1', 'name1', 'name1@email.com','name1');
insert into User(first_name, last_name, login, password, email, title) values ('name2', 'name2', 'name2', 'name2', 'name2@email.com','name2');
insert into User(first_name, last_name, login, password, email, title) values ('name3', 'name3', 'name3', 'name3', 'name3@email.com','name3');
insert into User(first_name, last_name, login, password, email, title) values ('name4', 'name4', 'name4', 'name4', 'name4@email.com','name4');
insert into User(first_name, last_name, login, password, email, title) values ('name5', 'name5', 'name5', 'name5', 'name5@email.com','name5');
insert into User(first_name, last_name, login, password, email, title) values ('name6', 'name6', 'name6', 'name6', 'name6@email.com','name6');
insert into User(first_name, last_name, login, password, email, title) values ('name7', 'name7', 'name7', 'name7', 'name7@email.com','name7');
insert into User(first_name, last_name, login, password, email, title) values ('name8', 'name8', 'name8', 'name8', 'name8@email.com','name8');
insert into User(first_name, last_name, login, password, email, title) values ('name9', 'name9', 'name9', 'name9', 'name9@email.com','name9');
insert into User(first_name, last_name, login, password, email, title) values ('name10', 'name10', 'name10', 'name10', 'name10@email.com','name10');
insert into User(first_name, last_name, login, password, email, title) values ('name11', 'name11', 'name11', 'name11', 'name11@email.com','name11');
insert into User(first_name, last_name, login, password, email, title) values ('name12', 'name12', 'name12', 'name12', 'name12@email.com','name12');
insert into User(first_name, last_name, login, password, email, title) values ('name13', 'name13', 'name13', 'name13', 'name13@email.com','name13');
insert into User(first_name, last_name, login, password, email, title) values ('name14', 'name14', 'name14', 'name14', 'name14@email.com','name14');
insert into User(first_name, last_name, login, password, email, title) values ('name15', 'name15', 'name15', 'name15', 'name15@email.com','name15');

insert into Chat(name, creator_id) values ("chat1", 1);
insert into Chat(name, creator_id) values ("chat2", 2);
insert into Chat(name, creator_id) values ("chat3", 3);
insert into Chat(name, creator_id) values ("chat4", 4);
insert into Chat(name, creator_id) values ("chat5", 5);
insert into Chat(name, creator_id) values ("chat6", 6);
insert into Chat(name, creator_id) values ("chat7", 7);
insert into Chat(name, creator_id) values ("chat8", 8);
insert into Chat(name, creator_id) values ("chat9", 9);
insert into Chat(name, creator_id) values ("chat10", 10);
insert into Chat(name, creator_id) values ("chat11", 11);
insert into Chat(name, creator_id) values ("chat12", 12);

insert into Message(chat_id, user_id, message) values (1, 1, "message1");
insert into Message(chat_id, user_id, message) values (1, 2, "message2");
insert into Message(chat_id, user_id, message) values (1, 3, "message3");
insert into Message(chat_id, user_id, message) values (2, 1, "message1");
insert into Message(chat_id, user_id, message) values (2, 2, "message2");
insert into Message(chat_id, user_id, message) values (2, 3, "message3");
insert into Message(chat_id, user_id, message) values (3, 1, "message1");
insert into Message(chat_id, user_id, message) values (3, 2, "message2");
insert into Message(chat_id, user_id, message) values (3, 3, "message3");
insert into Message(chat_id, user_id, message) values (4, 1, "message1");
insert into Message(chat_id, user_id, message) values (4, 2, "message2");
insert into Message(chat_id, user_id, message) values (4, 3, "message3");
insert into Message(chat_id, user_id, message) values (5, 1, "message1");
insert into Message(chat_id, user_id, message) values (5, 2, "message2");
insert into Message(chat_id, user_id, message) values (5, 3, "message3");
insert into Message(chat_id, user_id, message) values (6, 1, "message1");
insert into Message(chat_id, user_id, message) values (6, 2, "message2");
insert into Message(chat_id, user_id, message) values (6, 3, "message3");
insert into Message(chat_id, user_id, message) values (7, 1, "message1");
insert into Message(chat_id, user_id, message) values (7, 2, "message2");
insert into Message(chat_id, user_id, message) values (7, 3, "message3");


insert into UserToChat(chat_id, user_id) values(1, 1);
insert into UserToChat(chat_id, user_id) values(1, 2);
insert into UserToChat(chat_id, user_id) values(1, 3);
insert into UserToChat(chat_id, user_id) values(2, 1);
insert into UserToChat(chat_id, user_id) values(2, 2);
insert into UserToChat(chat_id, user_id) values(2, 3);
insert into UserToChat(chat_id, user_id) values(3, 1);
insert into UserToChat(chat_id, user_id) values(3, 2);
insert into UserToChat(chat_id, user_id) values(3, 3);
insert into UserToChat(chat_id, user_id) values(4, 1);
insert into UserToChat(chat_id, user_id) values(4, 2);
insert into UserToChat(chat_id, user_id) values(4, 3);
insert into UserToChat(chat_id, user_id) values(5, 1);
insert into UserToChat(chat_id, user_id) values(5, 2);
insert into UserToChat(chat_id, user_id) values(6, 3);